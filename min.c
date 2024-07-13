#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *link;
};

struct node *head = NULL;

struct node *insert(int item) 
{
    struct node *new= (struct node*)malloc(sizeof(struct node));
    if (new== NULL) 
    {
        printf("Memory allocation failed\n");
    }

    new->data = item;
    new->link = NULL;

    if (head == NULL) 
    {
        head = new;
    } 
    else 
    {
        new->link = head;
        head = new;
    }
    return head;
}

void swap() 
{
    if (head == NULL || head->link == NULL) 
    {
        return;
    }

    struct node *min = head;
    struct node *ptr = head->link;

    while (ptr != NULL) 
    {
        if (ptr->data < min->data) 
        {
            min = ptr;
        }
        ptr= ptr->link;
    }

    int temp = head->data;
    head->data = min->data;
    min->data = temp;
}

void display() 
{
    struct node *ptr = head;
    if (ptr == NULL) 
    {
        printf("Linked list is empty\n");
        return;
    }
    printf("Linked list elements: ");
    while (ptr != NULL) 
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void main() 
{
    int item, ch;
    printf("Enter 1-insert, 2-swap, 3-display\n");
    do {
        printf("Enter the option: ");
        scanf("%d", &ch);
        switch (ch) 
        {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &item);
                head = insert(item);
                break;
            case 2:
                swap();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    } while (ch != 4);
}
