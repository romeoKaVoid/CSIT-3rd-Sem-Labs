#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct queue
{
    int data;
    struct queue *next;
};
typedef struct queue Queue;
Queue *front = NULL, *rear = NULL;
void enqueue();
void dequeue();
void display();
int main()
{
    int choice = 0;
    printf("\n****************Queue Operations using Pointer******************\n");
    printf("--------------------------------------------------------------------\n");
    while (choice != 4)
    {
        printf("Choose any one operation from below...\n");
        printf("1) Enqueue\n2) Dequeue\n3) Traverse\n4) Exit\n");
        printf("\nYour Choice? ");
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
            printf("Exiting....");
            printf("\n\n\tBy Krishna Aryal");
            exit(0);
        default:
            printf("Please choose Valid Option!!\n");
            break;
        }
    }
    return 0;
}
void enqueue()
{
    Queue *new;
    new = (Queue *)malloc(sizeof(Queue));
    int item;
    printf("Enter the value to Enqueue: ");
    scanf("%d", &item);
    new->data = item;
    new->next = NULL;
    if (rear==NULL)
    {
        rear=front=new;
        // printf("Enqueue Successfull!!\n\n");
    }
    else{
        // new->data = item;
        rear->next = new;
        rear = new;
    }
    printf("Enqueue Successfull!!\n\n");
}
void dequeue(){
    Queue *temp;
    // int item;
    if (front==NULL)
    {
        printf("Queue is Empty!!\n\n");
        return;
    }
    else{
        temp = front;
        printf("Deleted element is: %d", temp->data);
        front = front->next;
        printf("\n\n");
    }
    free(temp);
}
void display(){
    Queue *temp;
    if (front==NULL)
    {
        printf("No elements to Display!!\n\n");
    }
    else{
        temp = front;
        printf("\nQueue elements are: \n");
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
        printf("\n\n");
    }
}