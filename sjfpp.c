#include <stdio.h>
#include <string.h>

struct process
{
    char name[10];
    int at, bt;
} p[20], temp;

struct gantt
{
    char gname[10];
    int st, ct, tt, wt;
} g[20];

void dash(int n, int j, int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int v = 0; v < g[j].ct - g[j].st; v++)
        {
            printf("--");
        }
        printf("*");
        j++;
    }
}

void gantt(int n, int count)
{
    int h = 0, l, j = 0, t = 0, i;
    dash(n, j, count);
    printf("\n");
    printf("|");
    for (i = 0; i < count; i++)
    {
        l = strlen(g[h].gname);
        for (int v = 0; v < g[h].ct - g[h].st - l / 2; v++)
        {
            printf("  ");
        }
        printf("%s", g[h].gname);
        printf("|");
        h++;
    }
    printf("\n");
    dash(n, j, count);
    printf("\n");
    printf("%d", g[t].st);
    for (i = 0; i < count; i++)
    {
        for (int v = 0; v < g[t].ct - g[t].st; v++)
        {
            printf(" ");
        }
        printf("  ");
        printf("%d", g[t].ct);
        t++;
    }
}

void sort(int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            // First sort by arrival time
            if (p[j].at > p[j + 1].at)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
            // If arrival time is the same, sort by burst time
            else if (p[j].at == p[j + 1].at && p[j].bt > p[j + 1].bt)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void main()
{
    int n, i, lim, j, num, count = 0;
    printf("Enter the number of processes\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the process name\n");
        scanf("%s", p[i].name);
        printf("Enter the arrival time\n");
        scanf("%d", &p[i].at);
        printf("Enter the burst time\n");
        scanf("%d", &p[i].bt);
    }
    printf("_______________________________________\n");
    printf("|Process|Arrival time|Burst time|\n");
    for (i = 0; i < n; i++)
    {
        printf("|%s\t|\t%d\t|\t%d\t|\n", p[i].name, p[i].at, p[i].bt);
    }
    printf("__________________________________________\n");
    sort(n);
    for (i = 0, num = 0, lim = 0; i < n;)
    {
        if (p[i].at > lim)
        {
            strcpy(g[num].gname, "idle");
            g[num].st = lim;
            lim = p[i].at;
            g[num].ct = lim;
            num++;
            count++;
        }
        strcpy(g[num].gname, p[i].name);
        g[num].st = lim;
        lim = g[num].st + p[i].bt;
        g[num].ct = lim;
        g[num].tt = g[num].ct - p[i].at;
        g[num].wt = g[num].tt - p[i].bt;
        num++;
        i++;
        count++;
    }
    printf("_______________________________________________________\n");
    printf("|Process|Completion time|Turn around time|Waiting time|\n");
    for (i = 0; i < num; i++)
    {
        printf("|%s\t|\t%d\t|\t%d\t|\t%d\t|\n", g[i].gname, g[i].ct, g[i].tt, g[i].wt);
    }
    printf("________________________________________________________\n");
    printf("GANTT CHART\n");
    gantt(n, count);
    printf("\n");
}