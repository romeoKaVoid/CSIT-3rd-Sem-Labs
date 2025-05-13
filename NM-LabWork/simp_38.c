#include <stdio.h>
#include <math.h>
#define f(x) (pow(x, 3) + 1)
int main()
{

    int i, n = 3;
    float a, b, f[3], h, Ig;
    printf("Enter the Lower & Upper Limits: ");
    scanf("%f%f", &a, &b);
    h = (b - a) / n;
    for (i = 0; i <= n; i++)
        f[i] = f(a + i * h);
    Ig = 3 * h / 8 * (f[0] + f[n] + 3 * (f[1] + f[2]));
    printf("\nUsing Simpson's 3/8 Rule:");
    printf("\nThe integration is %.4f", Ig);
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}