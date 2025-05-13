#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) (1/(1+x))
int main(){
    float a,h,x0,xn,fx0,fxn,term,v;
    int i,k;
    printf("Enter the Lower & Upper Limits: ");
    scanf("%f%f",&x0,&xn);
    printf("Enter the number of Segments: ");
    scanf("%d",&k);
    h = (xn-x0)/k;
    fx0 = f(x0);
    fxn = f(xn);
    term = fx0 + fxn;
    for (int i = 1; i <=k-1; i=i+2)
    {
        a = x0 + i*h;
        term = term + 4*(f(a));
    }
    for (int i = 2; i <=k-2; i=i+2)
    {
        a=x0+i*h;
        term = term + 2*(f(a));
    }
    v = h/3*term;
    printf("\nUsing Composite Simpson's 1/3 rule:");
    printf("\nValue of Integraion = %f\n",v);
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}