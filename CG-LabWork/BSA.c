//Bresenham's Line Drawing Algorithm
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
int main(){
    int gd=DETECT, gm, i;
    int x1,x2,y1,y2;
    float x,y,dx,dy,p;
    initgraph(&gd,&gm,(char*)"");
    printf("Enter the points x1 and y1: ");
    scanf("%d%d",&x1,&y1);
    printf("Enter the points x2 and y2: ");
    scanf("%d%d",&x2,&y2);
    dx = (float)(x2-x1);
    dy = (float)(y2-y1);
    p = (2*dy-dx);
    x=x1;
    y=y1;
    while (x<=x2)
    {
        putpixel(x,y,WHITE);
        x++;
        if (p<0)
        {
            p=p+2*dy;
        }
        else{
            y++;
            p=p+(2*dy)-(2*dx);
        }
    }
    outtextxy(175,100,"BSA Algorithm : Krishna");
    getch();
    return 0;
}