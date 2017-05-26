#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<iostream>
int x[5];;
int y[5];
void display();
int main()
{
    int gd=DETECT,gm;
    char ch;
    x[1]=x[0]=200;
    y[1]=y[0]=200;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    setcolor(2);
    circle(x[0],y[0],10);
    //setcolor(2);
   // circle(x-1,y,10);
    while(ch=getch())
    {
        while(!kbhit())
        {
        if(ch=='w')
        {
                y[0]=y[0]-5;
            display();
        }
        else if(ch=='s')
        {
         //   if(x[0]-x[2]>0||x[0]-x[2]<0)
                y[0]=y[0]+5;
            display();
        }
        else if(ch=='d')
        {
        //    if(y[0]>y[2]||y[0]<y[2])
                x[0]=x[0]+5;
            display();
        }
        else if(ch=='a')
        {
         //   if(y[0]>y[2]||y[0]<y[2])
                x[0]=x[0]-5;
            display();
        }
        y[1]=y[0];
        x[1]=x[0];
        }
    }
    return 0;
}
void display()
{
    delay(500);
    setcolor(0);
    circle(x[1],y[1],10);

    setcolor(2);
    circle(x[0],y[0],10);
}


