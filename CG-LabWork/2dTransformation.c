#include <stdio.h>
#include <graphics.h>
#include <math.h>
int translation(int x, int tx)
{
    return (x + tx);
}
int scale(int x, int k)
{
    return (x * k);
}
int main()
{
    int gd = DETECT, gm, i;
    int left, right, bottom, top, k1, k2, xr, yr, n;
    initgraph(&gd, &gm, (char *)"");
    printf("Enter left, right, top & bottom sides of Rectangle:\n");
    scanf("%d%d%d%d", &left, &right, &top, &bottom);
    rectangle(left, top, right, bottom);
begin:
    printf("Choose any one Transformation you want:\n");
    printf("1) Translation\n2) Reflection\n3) Scaling\n\n");
    printf("Your Choice? ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("Enter translating factor for x and y: ");
        scanf("%d%d", &k1, &k2);
        left = translation(left, k1);
        right = translation(right, k1);
        top = translation(top, k2);
        bottom = translation(bottom, k2);
        rectangle(left, top, right, bottom);
        outtextxy(100, 100, "2D Translation : Krishna");
        break;
    case 2:
        int a;
        do
        {
            printf("1) About X-axis\n2) About Y-axis\n");
            printf("Enter which reflection you want? ");
            scanf("%d", &a);
            if (a == 1)
            {
                k1 = fabs(bottom - top);
                top = bottom;
                rectangle(left, top, right, bottom + k1);
                outtextxy(100, 100, "2D Reflection along X-axis : Krishna");
                break;
            }
            else if (a == 2)
            {
                k1 = fabs(left - right);
                left = right;
                rectangle(left, top, right + k1, bottom);
                outtextxy(100, 100, "2D Reflection along Y-axis : Krishna");
                break;
            }
            else
            {
                printf("Wrong Choice!! Try Again.\n");
            }
        } while (a != 1 && a != 2);
        break;
    case 3:
        printf("Enter the Scaling factor: ");
        int b;
        scanf("%d", &b);
        top = scale(top, b);
        right = scale(right, b);
        left = scale(left, b);
        bottom = scale(bottom, b);
        rectangle(left, top, right, bottom);
        outtextxy(100, 100, "2D Scalling : Krishna");
        break;
    default:
        printf("Invalid Choice!! Please Choose valid one!!\n\n");
        goto begin;
        break;
    }
    // closegraph();
    getch();
    return 0;
}