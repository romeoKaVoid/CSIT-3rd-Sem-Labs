#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    int n, i, j, k;
    float sum = 0, a[10][10], u[10][10] = {0}, l[10][10] = {0};
    printf("Enter the Dimension of Matrix: ");
    scanf("%d", &n);
    printf("Enter the elements for %d x %d matrix:\n", n, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }
    // Compute Elements of L and U Matrix
    for (j = 0; j < n; j++)
    {
        u[0][j] = a[0][j];
    }
    for (i = 0; i < n; i++)
    {
        l[i][i] = 1;
    }
    for (i = 1; i < n; i++)
    {
        l[i][0] = a[i][0] / u[0][0];
    }
    for (j = 0; j < n; j++)
    {
        for (i = 0; i <= j; i++)
        {
            sum = 0;
            for (k = 0; k < i; k++)
            {
                sum = sum + (l[i][k] * u[k][j]);
            }
            u[i][j] = a[i][j] - sum;
        }

        for (i = j + 1; i < n; i++)
        {
            sum = 0;
            for (k = 0; k < j; k++)
            {
                sum = sum + (l[i][k] * u[k][j]);
            }
            l[i][j] = (a[i][j] - sum) / u[j][j];
        }
    }
    printf("\n     *******L Matrix********\n");
    for (i = 0; i < n; i++)
    {
        printf(" | ");
        for (j = 0; j < n; j++)
        {
            printf(" %.2f\t", l[i][j]);
        }
        printf("| \n");
    }
    printf("\n     ********U Matrix********\n");
    for (i = 0; i < n; i++)
    {
        printf(" | ");
        for (j = 0; j < n; j++)
        {
            printf(" %.2f\t", u[i][j]);
        }
        printf("| \n");
    }
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}
