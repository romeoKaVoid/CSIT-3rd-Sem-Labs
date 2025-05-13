#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 5
int queue[SIZE];
int front = 0, rear = -1;
void enqueue();
void dequeue();
void display();
int main()
{
    int choice;
    printf("\n**************Queue Operations using Array*****************\n");
    printf("-----------------------------------------------------------\n");
    while (choice != 4)
    {
        printf("Choose any one option from below...\n");
        printf("1) Enqueue\n2) Dequeue\n3) Display all Values\n4) Exit\n\n");
        printf("Your choice? ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            printf("\n\n\tBy Krishna Aryal");
            exit(0);
        default:
            printf("Invalid!! Please enter Valid choice!!\n\n");
            break;
        }
    }
    return 0;
}
void enqueue()
{
    int value;
    // int front = 0, rear = -1;
    if (rear >= SIZE - 1)
    {
        printf("Queue Overflow!!\n\n");
    }
    else
    {
        printf("Enter the value to Enqueue: ");
        scanf("%d", &value);
        rear++;
        queue[rear] = value;
        printf("Enqueue Successfull !!\n\n");
    }
}
void dequeue()
{
    // int front=0,rear=-1;
    int item;
    if (rear<front)
    {
        printf("Queue is Empty!!\n\n");
    }
    else
    {
        item = queue[front++];
        printf("Deleted element is: %d", item);
        printf("\n\n");
    }
}
void display()
{
    // int front=0,rear=-1; 
    if (rear<front)
    {
        printf("No elemens to Display!!\n\n");
    }
    else
    {
        printf("\nQueue elements are:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t",queue[i]);
        }
        printf("\n\n");
    }
}