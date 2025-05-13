#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int main()
{
    int x[4],y[4],i;
    double putx,puty,t;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
    for ( i = 0; i < 4; i++)
    {
        printf("Enter the x and y coordinates: ");
        scanf("%d%d",&x[i],&y[i]);
    }
    for ( i = 0; i < 3; i++)
    {
        line(x[i],y[i],x[i+1],y[i+1]);
    }
    for ( t = 0.0; t <=1.0; t=t+0.001)
    {
        putx = (pow(1-t,3)*x[0])+(3*t*pow(1-t,2)*x[1])+(3*t*t*(1-t)*x[2])+(pow(t,3)*x[3]);
        puty = (pow(1-t,3)*y[0])+(3*t*pow(1-t,2)*y[1])+(3*t*t*(1-t)*y[2])+(pow(t,3)*y[3]);
        putpixel(putx,puty,WHITE);
    }
    outtextxy(100, 100, "Bezier Curve : Krishna");
    getch();
    // closegraph();
    return 0;
}