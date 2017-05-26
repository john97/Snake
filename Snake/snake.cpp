#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<conio.h>
#include<math.h>
int x[100],y[100];
int cx[100],cy[100],fx,fy,l=2;
void display();
int getfood();
void food();
int main()
{

    int gd=DETECT,gm,x2,y2,i;
    char ch;

    cx[0]=x[0]=200;
    cx[1]=x[1]=180;
    cy[0]=y[0]=200;
    cy[1]=y[1]=200;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    for(i=2;i<=5;i++)
    {
     setcolor(15);
    rectangle(i,i,getmaxx()-i,getmaxy()-i);
    }
    setcolor(2);
    circle(x[0],y[0],10);
    setcolor(2);
    circle(x[1],y[1],10);
    food();
    //setcolor(2);
   // circle(x-1,y,10);
    while(ch=getch())
    {
        while(!kbhit())
        {
            if(y[0]>y[1])
            {
                if(ch=='w'||ch=='s')
                   y[0]=y[0]+20;
                else if(ch=='a')
                    x[0]=x[0]-20;
                 else if(ch=='d')
                    x[0]=x[0]+20;

            display();
            getfood();
            }
       else   if(x[0]>x[1])
           {
               if(ch=='a'||ch=='d')
                   x[0]=x[0]+20;
                else if(ch=='w')
                    y[0]=y[0]-20;
                 else if(ch=='s')
                    y[0]=y[0]+20;

            display();
            getfood();
        }
           else if(y[0]<y[1])
            {
                if(ch=='w'||ch=='s')
                   y[0]=y[0]-20;
                else if(ch=='a')
                    x[0]=x[0]-20;
                 else if(ch=='d')
                    x[0]=x[0]+20;

            display();
            getfood();
        }
         else  if(x[0]<x[1])
           {
               if(ch=='a'||ch=='d')
                   x[0]=x[0]-20;
                else if(ch=='w')
                    y[0]=y[0]-20;
                 else if(ch=='s')
                    y[0]=y[0]+20;

            display();
            getfood();
        }
        for(i=0;i<l;i++)
            {
              //  if(i!=l-1);
            cx[i]=x[i];
            cy[i]=y[i];
        }
        //delay(200);
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS        if(kbhit())
   delay(100);
        }
    }
    closegraph();
    return 0;
}
void display()
{
    int i;
    delay(300);
    for(i=0;i<l-1;i++)
    {
        x[i+1]=cx[i];
        y[i+1]=cy[i];
    }
        for(i=0;i<l;i++)
        {
            setcolor(0);
            circle(cx[i],cy[i],10);
            setcolor(2);
            circle(x[i],y[i],10);
        }
}
void food()
{
 int i, n;
   /* Intializes random number generator */
   srand(time(NULL));
fx=rand()%(400)+10;
fy=rand()%(400)+10;
setcolor(3);
circle(fx,fy,10);
}
int getfood()
{
    int a,b;
    a=pow(x[0]-fx,2);
    b=pow(y[0]-fy,2);
if(sqrt(a+b)<=20)
{
    setcolor(0);
    circle(fx,fy,10);
    l++;
    cx[l-1]=x[l-1]=cx[l-2];
    cy[l-1]=y[l-1]=cy[l-2];
    setcolor(2);
    circle(x[l-1],y[l-1],10);
    food();
}
}

