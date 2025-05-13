// Newton Raphson Method
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 20
#define E 0.0001
#define f(x) (exp(x) - x - 2)
#define f1(x) (exp(x) - 1) // Derivative of fx
int main()
{
    int count = 1;
    float x0, x1;
    start:
    printf("Enter the initial guess value: x0 ");
    scanf("%f", &x0);
    if (f1(x0) == 0){
        printf("Derivative is zero at guess value.Change the guess value\n");
        goto start;
    }
    else
    {
    begin:
        x1 = x0 - (f(x0) / f1(x0));
        if (fabs((x1 - x0) / x1) < E)
        {
            printf("The root is %f", x1);
            printf("\nNo. of iterations is %d", count);
        }
        else
        {
            x0 = x1;
            count++;
            if (count < MAX)
                goto begin;
            else
                printf("The process doesn't converge.");
        }
    }
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}