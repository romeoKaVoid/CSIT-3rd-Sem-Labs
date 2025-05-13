#include<stdio.h>
#include<conio.h>
int gcd(int a, int b){
    if (a==0)
    {
        return b;
    }
    else{
        return gcd(b%a,a);
    }
}
int main()
{
    int x,y;
    printf("Enter any two numbers to find GCD: ");
    label:
    scanf("%d%d",&x,&y);
    if (x<0||y<0)
    {
        printf("Please enter +ve numbers: ");
        goto label;
    }
    else{
        printf("gcd(%d,%d) = %d",x,y,gcd(x,y));
    }
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}