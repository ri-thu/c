#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *left, *right;
    int data;
};
struct Node *root;
struct Node *inOrderSuccessor, *ptr, *new, *parent;

void insert(int val)
{
    struct Node *ptr, *new, *parent;
    new = (struct Node *)malloc(sizeof(struct Node));
    new->data = val;
    new->right = new->left = NULL;
    if (root == NULL)
        root = new;
    else
    {
        ptr = root;
        while (ptr != NULL)
        {
            parent = ptr;
            if (ptr->data > val)
                ptr = ptr->left;
                        else
                ptr = ptr->right;
        }
        if (parent->data > val)
            parent->left = new;
        else
            parent->right = new;
    }
}

struct Node *getInOrderSuccessor(struct Node *ptr)
{
    ptr = ptr->right;
    while (ptr->left != NULL)
        ptr = ptr->left;
    return ptr;
}
void delete(int val)
{
    int succes;
    ptr = root;
    while (ptr != NULL)
    {
        if (ptr->data == val)
            break;
        else
        {
            parent = ptr;
            if (ptr->data > val)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
    }
    if (ptr == NULL)
        printf("Deletion not possible: Element not found!\n");
    else
    {
        if (ptr->left == NULL && ptr->right == NULL)
        {
            if (ptr == root)
                root = NULL;
            else if (parent->left == ptr)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        else if (ptr->right == NULL)
        {
            if (ptr == root)
                root = ptr->left;
            else if (parent->left == ptr)
                parent->left = ptr->left;
            else
                parent->right = ptr->left;
        }
        else if (ptr->left == NULL)
        {
            if (ptr == root)
                root = ptr->right;
            else if (parent->left == ptr)
                parent->left = ptr->right;
            else
                parent->right = ptr->right;
        }
        else
        {
            inOrderSuccessor = getInOrderSuccessor(ptr);
            delete (inOrderSuccessor->data);
            ptr->data = inOrderSuccessor->data;
        }
    }
}

void preorder(struct Node *ptr)
{
    if (ptr != NULL)
    {
        printf(" %d", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(struct Node *ptr)
{
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf(" %d", ptr->data);
    }
}

void inorder(struct Node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->left);
        printf(" %d", ptr->data);
        inorder(ptr->right);
    }
}

struct Node *search(int val)
{
    struct Node *ptr = root;
    while (ptr != NULL)
    {
        if (ptr->data == val)
        {
            printf("%d is found\n", val);
            break;
        }
        else if (ptr->data > val)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    if (ptr == NULL)
        printf("%d is not found\n", val);
}

void display()
{
	int t;
    if (root == NULL)
        printf("Tree is empty\n");
    else
    {
    	printf("Choose the mode of traversal\n");
    	scanf("%d",&t);
    	switch(t)
    	{
        	case 1:printf("Preorder representation of tree : ");
        			preorder(root);
        			printf("\n");
        			break;
        	case 2:printf("Inorder representation of tree : ");
        			inorder(root);
      				  printf("\n");
      				  break;
        	case 3:printf("Postorder representation of tree : ");
       				 postorder(root);
        			printf("\n");
        			break;
        	case 4:printf("Invalid choice\n");
        			break;
    	}
	}
}
int main()
{
    int choice, val;
    while (1)
    {
        printf("Select Operation:\n"
               "1. Insert\n2. Delete\n"
               "3. Search\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &val);
            insert(val);
            break;
        case 2:
            printf("Enter the value of Node to delete: ");
            scanf("%d", &val);
            delete (val);
            break;
        case 3:
            printf("Enter the value of Node to search: ");
            scanf("%d", &val);
            search(val);
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid input!\n");
        }
    }
    return 0;
}


/*OUTPUT

Select Operation:
1. Insert
2. Delete
3. Search
4. Display
5. Exit
1
Enter the value to insert: 8
Select Operation:
1. Insert
2. Delete
3. Search
4. Display
5. Exit
1
Enter the value to insert: 9
Select Operation:
1. Insert
2. Delete
3. Search
4. Display
5. Exit
1
Enter the value to insert: 10
Select Operation:
1. Insert
2. Delete
3. Search
4. Display
5. Exit
4
Choose the mode of traversal
1
Preorder representation of tree :  8 9 10
Select Operation:
1. Insert
2. Delete
3. Search
4. Display
5. Exit
4
Choose the mode of traversal
2
Inorder representation of tree :  8 9 10
Select Operation:
1. Insert
2. Delete
3. Search
4. Display
5. Exit
4
Choose the mode of traversal
3
Postorder representation of tree :  10 9 8
Select Operation:
1. Insert
2. Delete
3. Search
4. Display
5. Exit
3
Enter the value of Node to search: 9
9 is found
Select Operation:
1. Insert
2. Delete
3. Search
4. Display
5. Exit
2
Enter the value of Node to delete: 8
Select Operation:
1. Insert
2. Delete
3. Search
4. Display
5. Exit
4
Choose the mode of traversal
1
Preorder representation of tree :  9 10
Select Operation:
1. Insert
2. Delete
3. Search
4. Display
5. Exit
4
Choose the mode of traversal
1
Preorder representation of tree :  9 10
Select Operation:
1. Insert
2. Delete
3. Search
4. Display
5. Exit
2
Enter the value of Node to delete: 9
Select Operation:
1. Insert
2. Delete
3. Search
4. Display
5. Exit
4
Choose the mode of traversal
1
Preorder representation of tree :  10
Select Operation:
1. Insert
2. Delete
3. Search
4. Display
5. Exit
2
Enter the value of Node to delete: 10
Select Operation:
1. Insert
2. Delete
3. Search
4. Display
5. Exit
4
Tree is empty
Select Operation:
1. Insert
2. Delete
3. Search
4. Display
5. Exit
5*/



