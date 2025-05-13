#include<stdio.h>
#include<conio.h>
void Sort(int A[], int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (A[j]>A[j+1])
            {
                int temp = A[j];
                A[j]=A[j+1];
                A[j+1] = temp;
            }
        }
    }
}
void binSearch(int arr[], int, int);
int main()
{
    int A[50];
    int data;
    printf("**Welcome to Binary Search Algorithm**\n");
    printf("--------------------------------------\n");
    int n;
    printf("Enter the number of elements in array: ");  
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    Sort(A,n);
    printf("\nSorted array =");
    for (int i = 0; i < n; i++)
    {
        printf(" %d, ",A[i]);
    }
    printf("\nEnter the data to search: ");
    scanf("%d",&data);
    binSearch(A,n,data);
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}
void binSearch(int arr[], int n, int key){
    int LB=0, UB=n-1;
    int mid = (LB+UB)/2;
    while((key!=arr[mid])&&(LB<=UB)){
        if (key<arr[mid])
            UB = mid -1;
        else
            LB = mid + 1;
        mid = (LB+UB)/2;
    }
    if (key==arr[mid])
    {
        printf("%d is found at position %d\n",key,mid+1);
    }
    if (LB>UB)
    {
        printf("%d is not found in array!!\n",key);
    } 
}
