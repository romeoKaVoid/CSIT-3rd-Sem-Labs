#include <stdio.h>
#include <conio.h>
void linearSch(int arr[], int, int);
int main()
{
    int A[50], key;
    int n;
    printf("**Welcome to Linear Search Algorithm**\n");
    printf("-------------------------------------\n");
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    printf("Enter the number to search: ");
    scanf("%d", &key);
    linearSch(A, n, key);
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}
void linearSch(int arr[], int n, int data)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == data)
        {
            printf("%d is found at index arr[%d]\n", data, i);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("%d is not found in an array!!\n", data);
    }
}