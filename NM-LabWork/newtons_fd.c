#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 10
int fact(int n){
    if (n==1)
    {
            return 1;
    }
    else
        return(n*fact(n-1));
}
int main(){
    int n,i,j;
    float sum=0,pro,f[MAX],x[MAX],d[MAX][MAX],xp,h;
    printf("Enter the number of points: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of x[%d] and f[%d]:\n",i,i);
        printf("x[%d] = ",i);
        scanf("%f",&x[i]);
        printf("f[%d] = ",i);
        scanf("%f",&f[i]);
    }
    printf("\nEnter the value at which interpolated value is needed: ");
    scanf("%f",&xp);
    h = x[1]-x[0];
    for (i = 0; i < n; i++)
    {
        d[i][0] = f[i];
    }
    for (j = 1; j < n; j++)
    {
        for (i = 0; i < n-j; i++)
        {
           d[i][j] = d[i+1][j-1] - d[i][j-1];
        }
    }
    printf("\nThe forward Divided Difference Table is:\n");
    printf("---------------------------------------------\n");
    printf("x(i) \t y(i) \t y1(i) \t y2(i) \t y3(i) \t y4(i)");
    printf("\n---------------------------------------------");
    for (i = 0; i < n; i++)
    {
        printf("\n%.3f",x[i]);
        for (j = 0;  j< n-i; j++)
        {
            printf("\t%.3f",d[i][j]);
        }
    }
    sum = f[0];
    for (i = 1; i < n; i++)
    {
        pro = 1.0;
        for (j = 0; j <i; j++)
        {
            pro = pro*(xp-x[j]);
        }
        sum = sum + (d[0][i]*pro/(pow(h,i)*fact(i)));
    }
    printf("\n\nInterpolated Value = %f",sum);
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}