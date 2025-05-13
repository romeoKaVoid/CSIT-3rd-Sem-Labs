#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <process.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *tos = NULL;
void push();
void pop();
void display();
int main()
{
    int choice = 0;
    printf("\n**************Stack Operations Using Pointer**************\n");
    printf("----------------------------------------------------------\n");
    while (choice != 4)
    {
        printf("Choose any one operation from below...\n");
        printf("1) Push\n2) Pop\n3) Traverse\n4) Exit\n");
        // choice=choice+4;
        printf("\nYour Choice? ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...");
            printf("\n\n\tBy Krishna Aryal");
            exit(0);

        default:
            printf("Please choose Valid Option!!\n");
            break;
        }
    }
    return 0;
}
void push()
{
    NODE *ptr;
    ptr = (NODE *)malloc(sizeof(NODE));
    int item;
    printf("Enter the value to be pushed: ");
    scanf("%d", &item);
    if (tos == NULL)
    {
        ptr->data = item;
        ptr->next = NULL;
        tos = ptr;
        printf("Value pushed!!\n\n");
    }
    // else if (!ptr)
    // {
    //     printf("Stack Overflow!! Cannot Push!!\n");
    // }
    else
    {
        ptr->data = item;
        ptr->next = tos;
        tos = ptr;
        printf("Value pushed!!\n\n");
    }
}
void pop()
{
    NODE *temp;
    if (tos == NULL)
    {
        printf("Stack is Empty!!\n\n");
        return;
    }
    else
    {
        temp = tos;
        tos = tos->next;
        printf("The popped element is: %d\n\n", temp->data);
        free(temp);
    }
}
void display(){
    NODE *temp;
    if(tos==NULL){
        printf("Stack Empty!!\n\n");
        return;
    }
    else{
        temp = tos;
        printf("Stack Elements from Top to Bottom are:\n");
        while (temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}