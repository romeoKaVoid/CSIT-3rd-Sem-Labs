#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 10
int main(){
    int n,i,j;
    float v=0,p,xv,x[MAX],fx[MAX],a[MAX];
    printf("Enter the number of points: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of x[%d] and fx[%d]:\n",i,i);
        printf("x[%d] = ",i);
        scanf("%f",&x[i]);
        printf("fx[%d] = ",i);
        scanf("%f",&fx[i]);
    }
    printf("\nEnter the value of given x: ");
    scanf("%f",&xv);
    for (int i = 0; i < n; i++)
    {
        a[i] = fx[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j >i; j--)
        {
            a[j] =(a[j]-a[j-1])/(x[j]-x[j-i-1]);
        }
    }
    v=0;
    for (int i = 0; i < n; i++)
    {
        p=1;
        for (int j = 0; j <=i-1; j++)
        {
            p=p*(xv-x[j]);
        }
        v=v+a[i]*p;
    }
    printf("\nInterpolation value = %f",v);
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}