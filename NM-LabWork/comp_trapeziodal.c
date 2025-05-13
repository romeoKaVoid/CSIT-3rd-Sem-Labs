#include <stdio.h>
#include <math.h>
#define MAX 10
#define f(x) (3 * (x) * (x) + 2 * (x) - 5)
int main()
{
    int i, n;
    float a, b, f[MAX], h, sum = 0, Ig;
    printf("Enter the Lower & Upper Limits: ");
    scanf("%f%f", &a, &b);
    printf("Enter the no. of segments: ");
    scanf("%d", &n);
    h = (b - a) / n;
    for (i = 0; i <= n; i++)
        f[i] = f(a + i * h);
    for (i = 1; i <= n - 1; i++)
        sum += f[i];
    Ig = h / 2 * (f[0] + f[n] + 2 * sum);
    printf("\nThe integration is %.4f", Ig);
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}