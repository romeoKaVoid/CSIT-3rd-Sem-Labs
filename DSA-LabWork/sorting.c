#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void bubble_sort(int B[], int n);
void insertion_sort(int A[], int n);
void selection_sort(int A[], int n);
void quick_sort(int A[], int l, int r);
void merge_sort(int A[], int l, int r);
void Heap_sort(int A[], int n);

// Array Display Function
void display(int B[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", B[i]);
    }
    printf("\n");
}

// Element Swap Function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick sort
int partition(int A[], int low, int up)
{
    int x = low, y = up;
    int p = A[low];
    while (x < y)
    {
        while (A[x] <= p)
        {
            x++;
        }
        while (A[y] > p)
        {
            y--;
        }
        if (x < y)
        {
            swap(&A[x], &A[y]);
        }
    }
    A[low] = A[y];
    A[y] = p;
    return y;
}

// Merge Function for MergeSort
void merge(int A[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = A[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = A[m + 1 + j];
    }
    i = j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

// Heapify function for Heap Sort
void heapify(int arr[], int n, int i)
{
    int largest = i; // initialiaze largest as root
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) // If left child is larger than root
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) // If right child is larger than root
    {
        largest = r;
    }
    if (largest != i) // If largest is not root
    {
        swap(&arr[i], &arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
int main()
{
    int A[50], n, choice = 0;
    printf("**Welcome to Array Sort Program**\n");
    printf("--------------------------------\n");
    printf("First, enter the number of elements in array: ");
    scanf("%d", &n);
    int left = 0, right = n - 1;
    printf("Enter %d elements in Array:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    while (choice != 7)
    {
        printf("\nPlease Choose a Sorting Method:\n");
        printf("1) Bubble Sort\n2) Insertion Sort\n3) Selection Sort\n4) Quick Sort\n5) Merge Sort\n6) Heap Sort\n7) Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        int temp_arr[n];
        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                temp_arr[i] = A[i];
            }
            bubble_sort(temp_arr, n);
            printf("Sorted Using Bubble Sort: ");
            display(temp_arr, n);
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                temp_arr[i] = A[i];
            }
            insertion_sort(temp_arr, n);
            printf("Sorted Using Insertion Sort: ");
            display(temp_arr, n);
            break;
        case 3:
            for (int i = 0; i < n; i++)
            {
                temp_arr[i] = A[i];
            }
            selection_sort(temp_arr, n);
            printf("Sorted Using Selection Sort: ");
            display(temp_arr, n);
            break;
        case 4:
            for (int i = 0; i < n; i++)
            {
                temp_arr[i] = A[i];
            }
            quick_sort(temp_arr, left, right);
            printf("Sorted Using Quick Sort: ");
            display(temp_arr, n);
            break;
        case 5:
            for (int i = 0; i < n; i++)
            {
                temp_arr[i] = A[i];
            }
            merge_sort(temp_arr, left, right);
            printf("Sorted Using Merge Sort: ");
            display(temp_arr, n);
            break;
        case 6:
            for (int i = 0; i < n; i++)
            {
                temp_arr[i] = A[i];
            }
            Heap_sort(temp_arr, n);
            printf("Sorted Using Heap Sort: ");
            display(temp_arr, n);
            break;
        case 7:
            printf("Exiting...");
            printf("\n\n\tBy Krishna Aryal");
            exit(0);
            break;
        default:
            printf("Please choose Valid Option!!\n");
            break;
        }
    }
}
void bubble_sort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j],&A[j+1]);
            }
        }
    }
}
void insertion_sort(int A[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = A[i];
        for (j = i - 1; j >= 0 && A[j] > key; j--)
        {
            A[j + 1] = A[j];
        }
        A[j + 1] = key;
    }
}
void selection_sort(int A[], int n)
{
    int least;
    for (int i = 0; i < n; i++)
    {
        least = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[least])
            {
                least = j;
            }
        }
        swap(&A[least], &A[i]);
    }
}
void quick_sort(int A[], int l, int r)
{
    int p;
    if (l < r)
    {
        p = partition(A, l, r);
        quick_sort(A, l, p - 1);
        quick_sort(A, p + 1, r);
    }
}
void merge_sort(int A[], int l, int r)
{
    int m;
    if (l < r)
    {
        m = (l + r) / 2;         
        merge_sort(A, l, m);     // Divide
        merge_sort(A, m + 1, r); // Conquer
        merge(A, l, m, r);       // Combine
    }
}
void Heap_sort(int A[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(A, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&A[0], &A[i]); // Move current root to end
        heapify(A, i, 0);   // call max heapify on the reduced heap
    }
}