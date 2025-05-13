#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) (x)*(x)*(x)+3*(x)*(x)
int main(){
    float a,h,x0,xn,fx0,fxn,term,v;
    int i,k;
    printf("Enter the Lower & Upper Limit: ");
    scanf("%f%f",&x0,&xn);
    printf("Enter the Number of Segments: ");
    scanf("%d",&k);
    h=(xn-x0)/k;
    fx0 = f(x0);
    fxn = f(xn);
    term = f(x0)+f(xn);
    for (int i = 1; i <=k-1; i++)
    {
        if (i%3!=0)
        {
            a=x0+i*h;
            term = term + 3*(f(a));
        }
        else{
            a = x0+i*h;
            term = term + 2*(f(a));
        }
    }
    v = 3/8.0*h*term;
    printf("\nUsing Composite Simpson's 3/8 Rule:");
    printf("\nValue of Integration = %f\n",v);
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}