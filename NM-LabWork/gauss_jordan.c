/*Gauss Jordan Method */
#include <stdio.h>
#include <math.h>
#define MAX 10

int main()
{
    int i, j, k, n;
    float a[MAX][MAX], c;
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
    /*forward and backward Elimination process*/

    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            if (i != k)
            {
                c = a[i][k] / a[k][k];
                for (j = k; j <= n + 1; j++)
                {
                    a[i][j] = a[i][j] - c * a[k][j];
                }
            }
        }
    }

    printf("\nThe reduced echelon form matrix is:\n");
    for (i = 1; i <= n; i++)
    {
        a[i][n + 1] /= a[i][i];
        a[i][i] /= a[i][i]; /*making diagonal element identity*/
        printf(" | ");
        for (j = 1; j <= n + 1; j++)
        {
            printf(" %.2f\t", a[i][j]);
        }
        printf("| \n");
    }
    printf("\nThe solution set using Gauss-Jordan Method is:\n");
    for (i = 1; i <= n; i++)
    {
        printf("x[%d] = %.4f\n", i, a[i][n + 1]);
    }
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}