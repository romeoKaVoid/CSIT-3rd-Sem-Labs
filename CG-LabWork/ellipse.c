#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
void display();
int x,y,xc,yc;
int main()
{
    int gd = DETECT, gm;
    int rx, ry;
    float p;
    initgraph(&gd, &gm, (char *)"");
    printf("Enter the coordinates of center:\n");
    printf("Xc = ");
    scanf("%d", &xc);
    printf("Yc = ");
    scanf("%d", &yc);
    printf("Enter x-radius and y-radius: ");
    scanf("%d%d", &rx, &ry);
    x = 0, y = ry;
    p = (ry * ry) - (rx * rx * ry) + (rx * rx) / 4;
    while ((2 * ry * ry * x) <= (2 * rx * rx * y))
    {
        x++;
        if (p < 0)
        {
            p = p + (2 * ry * ry * x) + (ry * ry);
        }
        else
        {
            y--;
            p = p + (2 * ry * ry * x) - (2 * rx * rx * y) + (ry * ry);
        }
        display();
    }
    p = (ry * ry * (x + 0.5) * (x + 0.5)) + (rx * rx * (y - 1) * (y - 1)) - (rx * rx * ry * ry);
    while (y > 0)
    {
        if (p <= 0)
        {
            x++;
            y--;
            p = p + (2 * ry * ry * x) - (2 * rx * rx * y) + (rx * rx);
        }
        else
        {
            y--;
            p = p - (2 * rx * rx * y) + (rx * rx);
        }
        display();
    }
    outtextxy(100, 100, "Ellipse Mid-Point Algorithm : Krishna");
    getch();
    // closegraph();
    return 0;
}
void display(){
    putpixel(xc+x,yc+y,WHITE);
    putpixel(xc+x,yc-y,WHITE);
    putpixel(xc-x,yc+y,WHITE);
    putpixel(xc-x,yc-y,WHITE);
}