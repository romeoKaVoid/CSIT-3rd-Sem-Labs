#include<stdio.h>
#include<conio.h>
#define MAX 10
int main()
{
    int n,i,j;
    float xp,fp,x[MAX],f[MAX],L[MAX],sum=0,pro;
    printf("Enter the number of points: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("\nInput the data points for x[%d] & f[%d]",i,i);
        printf("\nx[%d] = ",i);
        scanf("%f",&x[i]);
        printf("f[%d] = ",i);
        scanf("%f",&f[i]);
    }
    printf("\nInput the specified value of x: ");
    scanf("%f",&xp);
    for (int i = 0; i <n; i++)
    {
        pro = 1.0;
        for (int j = 0; j <n; j++)
        {
            if (i!=j)
            {
                pro = pro*(xp-x[j])/(x[i]-x[j]);
            }
        }
        L[i] = pro;
    }
    for (int i = 0; i < n; i++)
    {
        sum = sum +L[i]*f[i];
    }
    fp = sum;
    printf("\nThe required functional value at %.3f = %f",xp,fp);
    getch();
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}