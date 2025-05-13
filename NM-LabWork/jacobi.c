/*Jacobi Method*/
#include <stdio.h>
#include <math.h>
#define MAX 10
#define E 0.0001
#define N 100
int main()
{
    int i, j, k, n;
    float a[MAX][MAX], x[MAX], x0[MAX], sum;
    printf("Enter the no. of unknowns: ");
    scanf("%d", &n);
    printf("Enter %d x %d elements for the augmented matrix:\n", n, n + 1);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }
    printf("\nThe Solution Process is:\n");
    printf("x1(k+1)\tx2(k+1)\tx3(k+1)\n");
    printf("------------------------\n");
    for (i = 1; i <= n; i++)
    {
        x0[i] = 0;
    }
    for (k = 1; k <= N; k++)
    {
        for (i = 1; i <= n; i++)
        {
            sum = 0;
            for (j = 1; j <= n; j++)
            {
                if (i != j)
                    sum += a[i][j] * x0[j];
            }
            x[i] = (-sum + a[i][n + 1]) / a[i][i];
            printf("%.3f\t|",x[i]);
        }
        printf("\n");
        if ((fabs(x[1] - x0[1]) / x[1]) < E)
            break;

        for (i = 1; i <= n; i++)
        {
            x0[i] = x[i];
        }
    }
    if (k == N + 1)
        printf("Maximum number of iterations exceeded.");
    else
    {
        printf("\nThe solution set using Jacobi's Iterative Method is:\n");
        for (i = 1; i <= n; i++)
        {
            printf("x[%d] = %.3f\n", i, x[i]);
        }
    }
    printf("\nThe no. of iteration: %d", k);
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}