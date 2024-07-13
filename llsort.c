#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *head = NULL,*ptr;
struct node *insertbeg() {
    int item;
    printf("Enter the item to insert: ");
    scanf("%d", &item);
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = item;
    new->link = head;
    head = new;

    return head;
}

void display(struct node *ptr) 
{
    printf("Linked List: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void bubble(struct node *first) 
{
    int swap, temp;
    
    struct node *last = NULL;
    
    if (first == NULL)
        return;

    do {
        swap = 0;
        ptr = first;
        while (ptr->link != last) {
            if (ptr->data > ptr->link->data) 
            {
                temp = ptr->data;
                ptr->data = ptr->link->data;
                ptr->link->data = temp;
                swap = 1;
            }
            ptr = ptr->link;
        }
        last = ptr;
    } while (swap);
}
void main() 
{
    int ch;
    
        printf("\nEnter 1 to insert an element\t2-sort\t3-display\n");
        do{
        printf("Enter the choice\n");
        scanf("%d", &ch);
        switch (ch) 
        {
            case 1:
                    head = insertbeg();
                    display(head);
                    break;
            case 2:
                    bubble(head);
                    printf("List sorted successfully.\n");
                    break;
            case 3:
                    display(head);
                    break;
            default:
                    printf("Invalid choice!\n");
        }
    } while (ch!=3);
}
