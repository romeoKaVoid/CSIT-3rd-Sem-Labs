#include <stdio.h>
#include <conio.h>
long long int fact(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}
int main()
{
    int a;
label:
    printf("Enter the number you want factorial of: ");
    scanf("%d", &a);
    if (a < 0)
    {
        printf("Invalid Number!! Factorial of -ve number is not defined!!\n");
        goto label;
    }
    else
    {
        printf("The factorial of %d is %lld", a, fact(a));
    }
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}