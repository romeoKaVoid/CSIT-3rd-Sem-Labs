#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;
void enqueue();
void dequeue();
void display();
int main()
{
    int choice;
    printf("\n***************Circular Queue Operations**************\n");
    printf("----------------------------------------------------------\n");
    while (choice != 4)
    {

        printf("Choose any one option from below...\n");
        printf("1) Enqueue\n2) Dequeue\n3) Traverse\n4) Exit\n\n");
        printf("Your Choice? ");
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
            printf("Exiting...");
            printf("\n\n\tBy Krishna Aryal");
            exit(0);
        default:
            printf("Please choose Valid Option!!\n\n");
            break;
        }
    }
    return 0;
}
void enqueue()
{
    int item;
    // Checkig either queue has elemnts to ts full capacity
    if ((rear+1)%SIZE==front)
    {
        printf("Queue is full!!\n\n");
        return;
    }
    else{
        printf("Enter the value to Enqueue: ");
        scanf("%d",&item);
        // Checking if queue is empty
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else
        {
            // checking if full and rotating queue to 1st
            // if (rear == SIZE - 1)
            // {
            //     rear = 0;
            // }
            rear = (rear + 1) % SIZE; // incremented rear by 1
        }
        queue[rear] = item;
        printf("Enqueue Successfull!!\n\n");
    }
}
void dequeue()
{
    int item;
    // Check if Queue has any elements or not
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty!!\n\n");
        return;
    }
    else{
        item = queue[front];
        // Check if queue becomes empty after deleting elements
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
                front = (front + 1) % SIZE; // increment front by one
        }
        printf("Deleted element is: %d\n\n",item);
    }
}
void display()
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("No elements to Display!!\n\n");
        return;
    }
    else{
        printf("Queue Elements are:\n");
        for (i =front; i!=rear; i=(i+1)%SIZE)
        {
            printf("%d\t",queue[i]);
        }
        printf("%d\t",queue[i]);
        printf("\n\n");
        }
}
