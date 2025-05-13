#include <stdio.h>
#include <conio.h>
int fibo(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    // else if (n == 1)
    // {
    //     return 1;
    // }
    else
    {
        return fibo(n - 1) + fibo(n - 2);
    }
}
int main()
{
    int n;
    printf("Enter the no. of terms in the sequence: ");
    scanf("%d", &n);
    if (n < 0)
    {
        printf("Fibonacci sequence is not defined for -ve numbers!!");
    }
    else
    {
        printf("The fibonacci sequence upto %dth term is:\n", n);
        for (int i = 0; i < n; i++)
        {
            // to avoid last comma
            if (i == n - 1)
            {
                printf("%d", fibo(i));
            }
            else
            {
                printf("%d, ", fibo(i));
            }
        }
        printf("\n");
    }
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}