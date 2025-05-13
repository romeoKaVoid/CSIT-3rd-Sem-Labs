#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *start = NULL;
void createEmptyList(NODE *start)
{
    start = (NODE *)malloc(sizeof(NODE));
    if (start == NULL)
    {
        printf("Memory allocation failed!!\n\n");
        exit(0);
    }
    else
    {
        printf("Successfully Created an empty Node!!\n\n");
    }
}
void in_beg(int);
void in_pos(int);
void in_end(int);
void del_beg();
void del_pos();
void del_end();
void display();
int main()
{
    int choice;
    int item;
    printf("\n****************Operations on Singly Linked List****************\n");
    printf("-----------------------------------------------------------------\n");
    while (choice != 9)
    {
        printf("Choose any one operations from below...\n");
        printf("1) Creation\nInsertion\n\t2) Insert at Beginning\n\t3) Insert at Specified Position\n\t4) Insert at End\nDeletion\n\t5) Delete from Beginning\n\t6) Delete from Specified Position\n\t7) Delete from End\n8) Traverse\n9)Exit\n\n");
        printf("Your Choice? ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createEmptyList(start);
            break;
        case 2:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            in_beg(item);
            break;
        case 3:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            in_pos(item);
            break;
        case 4:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            in_end(item);
            break;
        case 5:
            del_beg();
            break;
        case 6:
            del_pos();
            break;
        case 7:
            del_end();
            break;
        case 8:
            display();
            break;
        case 9:
            printf("Exiting...");
            printf("\n\n\tBy Krishna Aryal");
            exit(0);
            break;
        default:
            printf("Invalid Choice!! Choose Wisely!!\n\n");
            break;
        }
    }
    // createEmptyList(start);
    return 0;
}
void in_beg(int item)
{
    NODE *ptr;
    ptr = (NODE *)malloc(sizeof(NODE));
    ptr->data = item;
    if (start == NULL)
    {
        ptr->next = NULL;
    }
    else
    {
        ptr->next = start;
    }
    start = ptr;
    printf("Value inserted at Beginning!!\n\n");
}
void in_pos(int item)
{
    NODE *ptr, *temp;
    int pos;
    printf("Enter at which node you want to insert data: ");
    scanf("%d", &pos);
    temp = start;
    for (int i = 1; i < pos - 1; i++)
    {
        // temp = temp->next;
        if (temp == NULL)
        {
            printf("There is less than %d element!!\n\n", pos);
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("There is less than %d element!!\n\n", pos);
        return;
    }
    ptr = (NODE *)malloc(sizeof(NODE));
    ptr->data = item;
    ptr->next = temp->next;
    temp->next = ptr;
    printf("Value inserted at %dth position!!\n\n", pos);
}
void in_end(int item)
{
    NODE *ptr, *temp;
    ptr = (NODE *)malloc(sizeof(NODE));
    ptr->data = item;
    ptr->next = NULL;
    if (start == NULL)
    {
        start = ptr;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        printf("Value inserted at End!!\n\n");
    }
}
void del_beg()
{
    NODE *temp;
    if (start == NULL)
    {
        printf("List is Empty!!\n\n");
        return;
    }
    else
    {
        temp = start;
        printf("Deleted item = %d", temp->data);
        start = temp->next;
        free(temp);
    }
    printf("\n\n");
}
void del_pos()
{
    NODE *temp, *p;
    if (start == NULL)
    {
        printf("No any Nodes to delete!!\n\n");
        return;
    }
    else
    {
        int pos;
        printf("Enter position of node to delete: ");
        scanf("%d", &pos);
        temp = start;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        p = temp->next;
        printf("Deleted item = %d\n\n", p->data);
        temp->next = p->next;
        free(p);
    }
}
void del_end()
{
    NODE *temp, *p;
    if (start == NULL)
    {
        printf("List Empty!!\n\n");
        return;
    }
    temp = start;
    // If there's only one node
    if (temp->next == NULL)
    {
        printf("Deleted item = %d\n\n", temp->data);
        free(temp);
        start = NULL; // Update start to NULL
        return;
    }
    //Traverse till the second last node
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    //Store the last node
    p = temp->next;
    printf("Deleted item = %d\n\n", p->data);
    //Unlink the last node
    temp->next = NULL;
    free(p);
}
void display()
{
    NODE *temp;
    temp = start;
    if (start == NULL)
    {
        printf("No any Items to Display!!\n\n");
        return;
    }
    else
    {
        // temp=start;
        printf("Items in the Singly Linked List are:\n");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n\n");
    }
}