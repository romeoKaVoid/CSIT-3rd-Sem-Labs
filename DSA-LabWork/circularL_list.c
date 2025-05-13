#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *start=NULL,*last=NULL;
void createCList(NODE *start){
    start = (NODE*)malloc(sizeof(NODE));
    if (start==NULL)
    {
        printf("Memory Allocation failed!!\n\n");
        exit(0);
    }
    else{
        printf("Successfully created an Empty List!!\n\n");
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
    int choice,item;
    printf("\n******************Operations on Circular Linked List************\n");
    printf("---------------------------------------------------------------------\n");
    while (choice!=9)
    {
        printf("Choose any one operation to perform from below...\n");
        printf("1) Creation\nInsertion\n\t2) Insert at Beginning\n\t3) Insert at Specified Position\n\t4) Insert at End\nDeletion\n\t5) Delete from Beginning\n\t6) Delete from Specified Position\n\t7) Delete from Ending\n8) Traverse\n9) Exit\n\n");
        printf("Your Choice? ");
        scanf("%d",&choice);   
        switch (choice)
        {
        case 1:
            createCList(start);
            break;
        case 2:
            printf("Enter the item to be inserted: ");
            scanf("%d",&item);
            in_beg(item);
            break;
        case 3:
            printf("Enter the item to be inserted: ");
            scanf("%d",&item);
            in_pos(item);
            break;
        case 4:
            printf("Enter the item to be inserted: ");
            scanf("%d",&item);
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
            printf("Invalid Choice!!\n\n");
            break;
        }
    }
    return 0;
}
void in_beg(int item){
    NODE *ptr;
    ptr = (NODE *)malloc(sizeof(NODE));
    ptr->data =item;
    if (start==NULL)
    {
        ptr->next = ptr;
        start = ptr;
        last =ptr;
    }
    else{
        ptr->next = start;
        start = ptr;
        last->next = ptr;
    }
    printf("Value inserted at Beginning!!\n\n");
}
void in_pos(int item){
    NODE *ptr, *temp;
    int pos, i = 1;

    ptr = (NODE *)malloc(sizeof(NODE));
    ptr->data = item;
    
    if (start == NULL) {
        start = ptr;
        ptr->next = ptr;
        last = ptr;
        printf("No nodes! So, inserted at the beginning!!\n\n");
        return;
    }

    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    if (pos == 1) {
        in_beg(item);
        return;
    }

    temp = start;

    // Traverse to find the position
    while (i < pos - 1 && temp->next != start) {
        temp = temp->next;
        i++;
    }

    // If the position is greater than the number of nodes
    if (i < pos - 1) {
        printf("There are less than %d nodes!!\n\n", pos);
        return;
    }

    // Insert the node
    ptr->next = temp->next;
    temp->next = ptr;

    // Update last if inserted at the end
    if (temp == last) {
        last = ptr;
    }

    printf("Value inserted at %dth position!!\n\n", pos);
}

void in_end(int item){
    NODE *ptr;
    ptr=(NODE *)malloc(sizeof(NODE));
    ptr->data = item;
    if (start==NULL)
    {
        start=ptr;
        ptr->next = ptr;
        last = ptr;
    }
    else{
        last->next = ptr;
        last=ptr;
        ptr->next = start;
    }
    printf("Value inserted at the End!!\n\n");
}
void del_beg(){
    NODE *temp;
    temp = start;
    if (start==NULL)
    {
        printf("Empty List!!\n\n");
        return;
    }
    else if (start==last)
    {
        start=last=NULL;
        free(temp);
    }
    else{
        printf("Deleted Item = %d\n\n",temp->data);
        start = temp->next;
        last->next = start;
        free(temp);
    }
}
void del_pos(){
    NODE *temp,*p;
    int pos;
    temp = start;
    if (start==NULL)
    {
        printf("List Empty!!\n\n");
        return;
    }
    else if(pos==1){
        del_beg();
    }
    else{
        printf("Enter the position of node to Delete: ");
        scanf("%d",&pos);
        for (int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        p=temp->next;
        printf("Deleted item = %d\n\n",p->data);
        temp->next = p->next;
        free(p);
    }
}
void del_end(){
    NODE *temp;
    temp=last;
    if (last==NULL)
    {
        printf("No any nodes to Delete!!\n\n");
        return;
    }
    else if (start==last)
    {
        printf("Deleted item = %d",start);
        start=last=NULL;
        free(start);
        return;
    }
    else{
        while (temp->next!=last)
        {
            temp= temp->next;
        }
        printf("Deleted item = %d\n\n", last->data);
        free(last);
        last = temp;
        last->next = start;
    }
}
void display(){
    NODE *temp;
    if (start==NULL)
    {
        printf("No any items to Display!!\n\n");
        return;
    }
    else{
        temp = start;
        printf("The items in circular linked list are:\n");
       do
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        } while (temp!=start);
        printf("\n\n");
    }
}
