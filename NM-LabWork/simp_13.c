#include <stdio.h>
#include <math.h>
#define f(x) (3*(x)*(x) + 2*(x) - 5)
int main()
{
    int i, n = 2;
    float a, b, f[3], h, Ig;
    printf("Enter the Lower & Upper Limits: "); 
    scanf("%f%f",&a,&b); 
    h = (b - a) / n;
    for (i = 0; i <= n; i++)
        f[i] = f(a + i * h);
    Ig = h / 3 * (f[0] + f[n] + 4 * f[1]);
    printf("\nUsing Simpson's 1/3 Rule:");
    printf("\nThe integration is %f", Ig);
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}