#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
void insert(int);
void preorder(struct node *root);
void postorder(struct node *root);
void inorder(struct node *root);
int main()
{
    int choice, item;
    printf("\n********Welcome to Tree Traverse*********\n");
    printf("-------------------------------------------\n\n");
    while (choice !=5)
    {
        printf("Choose any one option from below...\n");
        printf("1) Insert an Element in BST\n2) Pre-Order Traversal\n3) Post-Order Traversal\n4) In-Order Traversal\n5) Exit\n\n");
        printf("Your Choice? ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item you want to insert in tree: ");
            scanf("%d", &item);
            insert(item);
            break;
        case 2:
            printf("The preorder traversal of the tree is\n");
            preorder(root);
            printf("\n\n");
            break;
        case 3:
            printf("\nThe postorder traversal of the tree is\n");
            postorder(root);
            printf("\n\n");
            break;
        case 4:
            printf("\nThe inorder traversal of the tree is\n");
            inorder(root);
            printf("\n\n");
            break;
        case 5:
            printf("Exiting...");
            printf("\n\n\tBy Krishna Aryal");
            exit(0);
            break;
        default:
            printf("Invalid Choice! Please Choose wisely!!\n\n");
            break;
        }
    }
    return 0;
}

void insert(int item)
{
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Can't Insert");
        return;
    }
    else
    {
        ptr->data = item;
        ptr->left = NULL;
        ptr->right = NULL;
        if (root == NULL)
        {
            root = ptr;
            root->left = NULL;
            root->right = NULL;
        }
        else
        {
            parentptr = NULL;
            nodeptr = root;
            while (nodeptr != NULL)
            {
                parentptr = nodeptr;
                if (item < nodeptr->data)
                {
                    nodeptr = nodeptr->left;
                }
                else
                {
                    nodeptr = nodeptr->right;
                }
            }
            if (item < parentptr->data)
            {
                parentptr->left = ptr;
            }
            else
            {
                parentptr->right = ptr;
            }
        }
        printf("Node Inserted\n\n");
    }
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}