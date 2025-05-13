//Mid Point Circle Drawing Algorithm
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void draw_circle(int,int,int);
void drawpoints(int, int, int, int);
int main(){
    int xc,yc,R;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
    printf("Enter the center of circle:\n");
    printf("Xc = ");
    scanf("%d",&xc);
    printf("Yc = ");
    scanf("%d",&yc);
    printf("Enter the radius of the circle: ");
    scanf("%d",&R);
    draw_circle(xc,yc,R);
    outtextxy(100,100,"Mid-Point Circle Algorithm : Krishna");
    getch();
    // closegraph();
    return 0;
}
void draw_circle(int xc,int yc,int rad){
    int x=0;
    int y=rad;
    int p=1-rad;
    drawpoints(x,y,xc,yc);
    for ( x = 0; y > x; x++)
    {
        if (p<0)
        {
            p=p+2*x+1;
        }
        else{
            p=p+2*(x-y)+1;
            y--;
        }
        drawpoints(x,y,xc,yc);
    }
}
void drawpoints(int x, int y, int xc, int yc){
    putpixel(xc+x,yc+y,WHITE);
    putpixel(xc+y,yc+x,WHITE);
    putpixel(xc-y,yc+x,WHITE);
    putpixel(xc-x,yc+y,WHITE);
    putpixel(xc-x,yc-y,WHITE);
    putpixel(xc-y,yc-x,WHITE);
    putpixel(xc+y,yc-x,WHITE);
    putpixel(xc+x,yc-y,WHITE);
}