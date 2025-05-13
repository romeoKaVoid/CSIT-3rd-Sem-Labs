#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int main(){
    int rcode_begin[4] ={0,0,0,0},rcode_end[4] = {0,0,0,0},region_code[4];
    int xmax,ymax,xmin,ymin,flag=0;
    float slope;
    int x,y,x1,y1,i,xc,yc;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
    printf("Enter xMin and yMin: ");
    scanf("%d%d",&xmin,&ymin);
    printf("Enter xMax and yMax: ");
    scanf("%d%d",&xmax,&ymax);
    printf("Enter initial points of line(x,y): ");
    scanf("%d%d",&x,&y);
    printf("Enter final points of line(x1,y1): ");
    scanf("%d%d",&x1,&y1);
    rectangle(xmin,ymin,xmax,ymax);
    line(x1,y1,x,y);
    line(0,0,600,0);
    line(0,0,0,600);
    if (y>ymax)
    {
        rcode_begin[0] = 1;
        flag = 1;
    }
    if (y<ymin)
    {
        rcode_begin[1] = 1;
        flag = 1;
    }
    if (x>xmax)
    {
        rcode_begin[2] = 1;
        flag=1;
    }
    if (x<xmin)
    {
        rcode_begin[3] = 1;
        flag = 1;
    }
    if (y1>ymax)
    {
        rcode_end[0]=1;
        flag = 1;
    }
    if (y1<ymin)
    {
        rcode_end[1] = 1;
        flag=1;
    }
    if (x1>xmax)        
    {
        rcode_end[2]=1;
        flag=1;
    }
    if (x1<ymin)
    {
        rcode_end[3] = 1;
        flag=1;
    }
    if (flag==0)
    {
        printf("No need to clip as it is already in the window!!\n");
    }
    flag=1;
    for ( i = 0; i < 4; i++)
    {
        region_code[i] = rcode_begin[i]&&rcode_end[i];
        if (flag==0)
        {
            printf("Line is outside window\n");
        }
        else{
            slope = (float)(y1-y)/(x1-x);
            if (rcode_begin[2]==0&&rcode_begin[3]==1)
            {
                y = y + (float)(xmin-x)*slope;
                x = xmin;
            }
            if (rcode_begin[2]==1&&rcode_begin[3]==0)
            {
                y = y + (float)(xmax-x)*slope;
                x=xmax;
            }
            if (rcode_begin[0]==1&&rcode_begin[1]==0)
            {
               x=x+(float)(ymax-y)/slope;
               y = ymax;
            }
            if (rcode_begin[0]==0&&rcode_begin[1]==1)
            {
                x = x+(float)(ymin-y)/slope;
                y = ymin;
            }
            if (rcode_end[2]==0&&rcode_end[3]==1)
            {
                y1 = y1 + (float)(xmin-x1)*slope;
                x1 = xmin;
            }
            if (rcode_end[2]==1&&rcode_end[3]==0)
            {
                y1 = y1 + (float)(xmax-x1)*slope;
                x1=xmax;
            }
            if (rcode_end[0]==1&&rcode_end[1]==0)
            {
               x1=x1+(float)(ymax-y1)/slope;
               y1 = ymax;
            }
            if (rcode_end[0]==0&&rcode_end[1]==1)
            {
                x1 = x1+(float)(ymin-y1)/slope;
                y1 = ymin;
            }
        }
    }
    delay(7000);
    clearviewport();
    rectangle(xmin,ymin,xmax,ymax);
    line(0,0,600,0);
    line(0,0,0,600);
    line(x1,y1,x,y);
    outtextxy(25,25,"Line Clipping Algorithm : Krishna");
    getch();
    // closegraph();
    return 0;
}