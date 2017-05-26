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

char str1[20];
int main()
{


    int gd=DETECT,gm,x2,y2,i;
    char ch;

    cx[0]=x[0]=200;
    cx[1]=x[1]=190;
    cy[0]=y[0]=200;
    cy[1]=y[1]=200;
    FILE *fp;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    outt\extxy(getmaxx()/2,getmaxy()/2,"Please  Enter Your Name");
    delay(1000);
    gets(str1);

            fp=fopen("ptr.txt","app");
            fputs("Name :",fp);
            fputs(str1,fp);
    cleardevice();
     for(i=150;i>=147;i--)
     {
         setcolor(15);
         rectangle(i,i,getmaxx()-i,getmaxy()-i);
         delay(50);
    }
    setcolor(4);
    setfillstyle(SOLID_FILL,RED);
    pieslice(x[0],y[0],0,360,5);
    setcolor(2);
    setfillstyle(SOLID_FILL,GREEN);
    pieslice(x[1],y[1],0,360,5);
    food();
     while(ch=getch())
    {
        while(!kbhit())
        {
            if(y[0]>y[1])
            {
                if(ch=='w'||ch=='s')
                   y[0]=y[0]+10;
                else if(ch=='a')
                    x[0]=x[0]-10;
                 else if(ch=='d')
                    x[0]=x[0]+10;
                    else if(ch=='q')
                        break;
                 getfood();
            }
       else if(x[0]>x[1])
           {
               if(ch=='a'||ch=='d')
                   x[0]=x[0]+10;
                else if(ch=='w')
                    y[0]=y[0]-10;
                 else if(ch=='s')
                    y[0]=y[0]+10;
                    else if(ch=='q')
                        break;
            getfood();
        }
           else if(y[0]<y[1])
            {
                if(ch=='w'||ch=='s')
                   y[0]=y[0]-10;
                else if(ch=='a')
                    x[0]=x[0]-10;
                 else if(ch=='d')
                    x[0]=x[0]+10;
                    else if(ch=='q')
                        break;
            getfood();
        }
         else  if(x[0]<x[1])
           {
               if(ch=='a'||ch=='d')
                   x[0]=x[0]-10;
                else if(ch=='w')
                    y[0]=y[0]-10;
                 else if(ch=='s')
                    y[0]=y[0]+10;
                    else if(ch=='q')
                        break;
            getfood();
        }
        for(i=0;i<l;i++)
            {
              //  if(i!=l-1);
            cx[i]=x[i];
            cy[i]=y[i];
        }
        //delay(200);
   delay(100);
        }
    }

    closegraph();
    return 0;
}
void display()
{
    int i;
  //ddddddddd
    delay(90);

    for(i=0;i<l-1;i++)
    {
        x[i+1]=cx[i];
        y[i+1]=cy[i];
    }
        for(i=0;i<l;i++)
        {

            setcolor(0);
            setfillstyle(SOLID_FILL,BLACK);
            pieslice(cx[i],cy[i],0,360,5);
            if(i!=0)
            {
            setcolor(2);
            setfillstyle(SOLID_FILL,GREEN);
            pieslice(x[i],y[i],0,360,5);
            }
            else
            {
                setcolor(4);
            setfillstyle(SOLID_FILL,RED);
            pieslice(x[i],y[i],0,360,5);
         }
        }
}
void food()
{
 int i, n;
srand(time(NULL));
  do
  {

   fx=rand()%(getmaxx()-310)+155;
   fy=rand()%(getmaxy()-310)+155;
   fx=fx-fx%10;
   fy==fy-fy%10;
  }
   while(getpixel(fx,fy)!=BLACK);
   delay(30);
 setcolor(3);
 setfillstyle(SOLID_FILL,CYAN);
 pieslice(fx,fy,0,360,5);
}
int getfood()
{
    int a,b;
    a=pow(x[0]-fx,2);
    b=pow(y[0]-fy,2);
  if(a+b<100)
{
    setcolor(0);
    setfillstyle(SOLID_FILL,BLACK);
    pieslice(fx,fy,0,360,5);
    l++;
    cx[l-1]=x[l-1]=cx[l-2];
    cy[l-1]=y[l-1]=cy[l-2];
    food();
}
if(getpixel(x[0],y[0])!=0)
       {
           cleardevice();
           outtextxy(getmaxx()/2,getmaxy()/2,"GAME OVER");

    delay(1000);
    exit(0);
       }
display();
}
