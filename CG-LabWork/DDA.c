#include<stdio.h>
#include<graphics.h>
#include<math.h>
int main(){
    int gd=DETECT, gm, i;
    float xinc,yinc,x,y,dx,dy;
    int x1,y1,x2,y2,steps;
    printf("Enter x1 and x2: ");
    scanf("%d%d",&x1,&x2);
    printf("Enter y1 and y2: ");
    scanf("%d%d",&y1,&y2);
    printf("\n\n\tBy Krishna Aryal");
    initgraph(&gd,&gm,(char*)"");
    dx = (float)(x2-x1);
    dy = (float)(y2-y1);
    if (abs(dx)>abs(dy))
    {
        steps = abs(dx);
    }
    else{
        steps = abs(dy);
    }
    xinc = dx/steps;
    yinc = dy/steps;
    x = x1;
    y = y1;
    for ( i = 0; i < steps; i++)
    {
        x1 = x1 + xinc;
        y1 = y1 + yinc;
        putpixel(round(x1),round(y1),WHITE);
    }
    outtextxy(200,100,"DDA Algorithm: Krishna");
    getch();
    return 0;
}