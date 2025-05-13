#include<stdio.h>
#include<conio.h>
#define SIZE 100
int stack[SIZE],tos = -1,n;
void push();
void pop();
void display();
int main()
{
    int choice = 0;
    printf("Enter the number of elements in the stack: ");
    scanf("%d",&n);
    printf("\n*********Stack Operations Using Array***********\n");
    printf("-----------------------------------------------------\n");
    while (choice!=4)
    {
        printf("Choose any one option from below...\n");
        printf("1) Push\n2) Pop\n3) Traverse\n4) Exit\n");
        // choice = choice+4;
        printf("\nYour Choice? ");
        scanf("%d",&choice);
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
            printf("Exiting....");
            break;
            
            default:
            printf("Please enter the Valid Choice!!\n\n");
            break;
        }
    }
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}
void push(){
    int val;
    if (tos==n-1)
    {
        printf("The Stack is Full\n\n");
    }
    else{
        printf("Enter the value to be pushed: ");
        scanf("%d",&val);
        tos++;
        stack[tos] = val;
        printf("Value Pushed!!\n");
        printf("\n");
    }
}
void pop(){
    if (tos==-1)
    {
        printf("Stack is Empty!!\n\n");
    }
    else{
        printf("The popped element is: %d\n",stack[tos]);
        tos--;
        printf("\n");
    }
}
void display(){
    for (int i = tos; i >=0; i--)
    {
        printf("stack[%d] = %d\n",i,stack[i]);
    }
    printf("\n");
    if (tos==-1)
    {
        printf("Stack Empty!!\n\n");
    }
} 