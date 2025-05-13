#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
int translate(int x, int k)
{
    return (x + k);
}
int scale(int x, int k)
{
    return (x * k);
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    int a1, a2, b1, b2, k1, k2;
    int x1, x2, y1, y2, depth, mx, my;
    printf("Enter 1st top values for 3D Object(x1,y1): ");
    scanf("%d%d", &x1, &y1);
    mx = (x1 + x2) / 2;
    my = (y1 + y2) / 2;
    printf("Enter right bottom values for 3D Object(x2,y2): ");
    scanf("%d%d", &x2, &y2);
    depth = fabs((x2 - x1) / 4);
    bar3d(x1, y1, x2, y2, depth, WHITE);
    outtextxy(x1 + 50, y1 - 15, "Object");
begin:
    printf("Choose any one Transformation from below...\n");
    printf("1) Translation\n2) Scaling\n\n");
    printf("Your Choice? ");
    int c;
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        printf("Enter translating factors(tx,ty): ");
        scanf("%d%d", &k1, &k2);
        a1 = translate(x1, k1);
        a2 = translate(x2, k1);
        b1 = translate(y1, k2);
        b2 = translate(y2, k2);
        bar3d(a1, b1, a2, b2, depth, WHITE);
        outtextxy(a1 + 50, b1 - 15, "Image");
        outtextxy(25, 25, "3D Translation : Krishna");
        break;
    case 2:
        printf("Enter scaling factors: ");
        scanf("%d%d", &k1, &k2);
        a1 =scale(x1,k1);
        a2 =scale(x2,k1);
        b1 =scale(y1,k2);
        b2 =scale(y2,k2);
        bar3d(a1, b1, a2, b2, depth, WHITE);
        outtextxy(a1 + 25, b1 - 15, "Image");
        outtextxy(25, 25, "3D Scalling : Krishna");
        break;
    default:
        printf("Invalid Choice!! Please choose again..\n\n");
        goto begin;
        break;
    }
    getch();
    return 0;
}