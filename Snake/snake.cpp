#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<conio.h>
#include<math.h>
#include<fstream>
#include<string.h>
using namespace std;
int x[100], y[100], cx[100],cy[100],fx,fy,l,score1,stage;
void display();
void file();
int getfood();
void highscore();
void food();
void barier()
{
    int i,u;
         for(i=20;i>=17;i--)
     {
         setcolor(15);
         rectangle(i,i,getmaxx()-i,getmaxy()-i);
    }
     u = 3;
             setcolor(15);
    if( stage == 1 ){
    /*********** LEVEL 1 **********/
    bar(20, 330, 260, 330 + u);     // bottom H
    bar(260, 20, 260 + u, 230);     // left V
    bar(340, 100, 620, 100 + u);    // top H
    bar(460, 200, 460 + u, 460);    // right V
    bar(100, 100, 180, 100 + u);    // left T
    bar(140, 100, 140 + u, 180);
    bar(360, 280, 360 + u, 390);    // bottom angle
    bar(210, 390, 370, 390 + u);
    bar(490, 220, 520, 220 + u);    // stairs
    bar(520, 250, 550, 250 + u);
    bar(550, 280, 580, 280 + u);
    }
    else if( stage == 2){
    /************* LEVEL 2 ***********/
    bar(250, 270, 380, 270 + u);    // center
    bar(250, 230, 380, 230 + u);
    bar(30, 30, 100, 30 + u);         // top left
    bar(30, 30, 30 + u, 100);
    bar(600, 30, 600 + u, 100);       // top right
    bar(540, 30, 610, 30 + u);
    bar(600, 380, 600 + u, 450);      // bottom right
    bar(540, 440, 610, 440 + u);
    bar(30, 440, 100, 440 + u);      // bottom left
    bar(30, 380, 30 + u, 450);


    bar(320, 90, 320 + u, 140);       // above
    bar(110, 80, 110 + u, 150);         // L
    bar(530, 80, 530 + u, 150);       // R
    bar(190, 110, 250, 110 + u);
    bar(390, 110, 450, 110 + u);

    bar(320, 90 + 270, 320 + u, 140 + 270);       // down
    bar(110, 80 + 270, 110 + u, 150 + 270);         // L
    bar(530, 80 + 270, 530 + u, 150 + 270);       // R
    bar(180, 110 + 270, 240, 110 + u + 270);
    bar(390, 110 + 270, 450, 110 + u + 270);

    bar(200, 270, 230, 270 + u);
    bar(200, 230, 230, 230 + u);
    bar(400, 270, 430, 270 + u);
    bar(400, 230, 430, 230 + u);
    }
}
void controls();
int j,k=0,m,le;
char ch;
float s=0.0,n=0;
char str1[100];
int main()
{
int gd=DETECT,gm,x2,y2,i;

              for(i=0;i<l;i++)
              {
                  x[i]=cx[i]=0;
                  y[i]=cy[i]=0;
              }
              if(le==3)
                l=3;
              if(le==1)
                l=1;
    cx[0]=x[0]=200;
    cx[1]=x[1]=190;
    cy[0]=y[0]=200;
    cy[1]=y[1]=200;

    if(k==0)
    {
        printf("******************************************************************************\n");
    printf("Enter Your Name\n");
     gets(str1);
     printf("Enter The Level At Which U Want To Play\n");
     printf("    Press 1 For Level One\n");
     printf("    Press 2 For Level Two\n");
     printf("    Press 3 For Level Three\n");
     std::cin>>m;
     printf("    Press 1 for length one\n");
     printf("    Press 3 for length three\n");
     std::cin>>le;
     l=le;
        printf("\n\n                                       Enter the stage you want to play (1 or 2)\n\n\t\t\t\t\t\t");
     std::cin>>stage;
    while(stage > 2 || stage < 1 ){
            printf("                                           Error !!\n\n");
            printf("                                     Enter stage again (1 or 2)\n\n\t\t\t\t\t\t");
            std::cin>>stage;
     }
    }
    initgraph(&gd,&gm,"C:\\TC\\BGI");
     barier();

    setcolor(4);
    setfillstyle(SOLID_FILL,RED);
    pieslice(x[0],y[0],0,360,5);
    if(l!=1)
    {
    setcolor(2);
    setfillstyle(SOLID_FILL,GREEN);
    pieslice(x[1],y[1],0,360,5);
}
else
{
    x[1]=cx[1]=0;
    y[1]=cy[1]=0;
}
if(l==3)
{
    cx[2]=x[2]=180;
    cy[2]=y[2]=200;
    setcolor(2);
        setfillstyle(SOLID_FILL,GREEN);
    pieslice(x[2],y[2],0,360,5);
}
food();
     while(ch=getch())
     {

        while(!kbhit())
        {
            k++;
            if(y[0]>y[1])
            {
                if(ch=='w'&&l!=1)
                   y[0]=y[0]+10;
                   else if(ch=='s')
                    y[0]=y[0]+10;
                   else if(ch=='w'&&l==1)
                    y[0]=y[0]-10;
                else if(ch=='a')
                    x[0]=x[0]-10;
                 else if(ch=='d')
                    x[0]=x[0]+10;
                    else if(ch=='q'){
                        break;
                    }
                    else if(ch=='e')
                    {
                        s=0;
                        closegraph();
                        main();
                    }
                    else if(ch=='z')
                             {
                            controls();
                            ch='q';
                        }
                        else if(ch=='c')
                        {
                            highscore();
                            ch='q';
                        }
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
                    else if(ch=='q'){
                        break;
                    }
                    else if(ch=='e')
                    {
                        closegraph();
                        main();
                    }
                    else if(ch=='z')
                             {
                            controls();
                            ch='q';
                        }
                        else if(ch=='c')
                        {
                            highscore();
                            ch='q';
                        }
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
                    {
                        break;
                    }
                    else if(ch=='e')
                    {
                        closegraph();
                        main();
                    }
                    else if(ch=='z')
                             {
                            controls();
                            ch='q';
                        }
                        else if(ch=='c')
                        {
                            highscore();
                            ch='q';
                        }
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
                    {
                        break;
                    }
                    else if(ch=='e')
                    {
                      closegraph();
                        main();
                    }
                    else if(ch=='z')
                             {
                            controls();
                            ch='q';
                        }
                        else if(ch=='c')
                        {
                            highscore();
                            ch='q';
                        }
                 getfood();
    }
        for(i=0;i<l;i++)
            {
              //  if(i!=l-1);
            cx[i]=x[i];
            cy[i]=y[i];
        }
        //delay(200);
   if(m==1)
          n=170;
        if(m==2)
            n=135;
        if(m==3)
            n=90;
   delay(n);
        }
    }

    closegraph();
    return 0;
}
void display()
{
    int i;
  //ddddddddd
    if(m==1)
          n=.170;
        if(m==2)
            n=.135;
        if(m==3)
            n=0.09;
            s=s+n;
           if(ch!='q'&&ch!='z')
           {
    for(i=0;i<l-1;i++)
    {
        x[i+1]=cx[i];
        y[i+1]=cy[i];
    }
           }
    setcolor(0);
            setfillstyle(SOLID_FILL,BLACK);
            pieslice(cx[l-1],cy[l-1],0,360,5);

        for(i=0;i<l;i++)
        {
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
   fy=fy-fy%10;
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
  if(a+b<95)
{
    setcolor(0);
    setfillstyle(SOLID_FILL,BLACK);
    pieslice(fx,fy,0,360,5);
    l++;
    cx[l-1]=x[l-1]=cx[l-2];
    cy[l-1]=y[l-1]=cy[l-2];
    food();
}
char str2[30];
if(getpixel(x[0],y[0])!=0)
       {
           cleardevice();
           outtextxy(getmaxx()/2,getmaxy()/2,"GAME OVER");
           outtextxy(getmaxx()/2,getmaxy()/2+50," Press x For Undo ");
         outtextxy(getmaxx()/2,getmaxy()/2+100,"Press Any Key To Continue ");
           delay(100);
           if(getch()=='x')
           {
               ch='q';
               cleardevice();
               barier();
               x[0]=cx[0];
               y[0]=cy[0];
               display();
               food();
               return 1;
           }
           else
             {
                       outtextxy(getmaxx()/2,getmaxy()/2+50,"THANKS For Playing");
                 score1=s;
                 sprintf(str2,"Score :%d",score1);
                 outtextxy(getmaxx()/2,getmaxy()/2+150,str2);
                 file();
             }
    delay(20000);
    exit(0);
       }
display();
}
void file()
{
        char str[100][10];
    int score[100],b=0,j=0,k1,m1;
    fstream in;
    in.open("ptr.txt",ios::in|ios::out);
    if(in)
    {
    while(in>>str[b])
    {
        in>>score[b];
        b++;
    }
    }
    in.close();
    in.open("ptr.txt",ios::out);
    for(j=0;j<b;j++)
    {
        if(strcmp(str[j],str1)==0)
        {
            m1=1;
            if(score[j]<score1)
            {
                score[j]=score1;

            }
             break;
        }
    }
    if(j==b)
    {
         for(j=0;j<b;j++)
         {
             if(score1>=score[j])
                break;
         }
    }
    for(k1=0;k1<j;k1++)
    {
        in<<str[k1]<<endl;
        in<<score[k1]<<endl;
    }
    if(m1!=1)
    in<<str1<<endl<<score1<<endl;
        for(k1=j;k1<b;k1++)
    {
        in<<str[k1]<<endl;
        in<<score[k1]<<endl;
    }
   in.close();
}
void controls()
{
    int i;
    cleardevice();
    outtextxy(50,20,"Controls");
    setcolor(4);
    line(50,70,100,70);
    setcolor(10);
     outtextxy(50,70,"Press q For Pause");
     outtextxy(50,120,"Press e For Restart");
     outtextxy(50,170,"Press w For Moving Up");
     outtextxy(50,220,"Press s For Moving Down");
     outtextxy(50,270,"Press a For Moving Left");
     outtextxy(50,320,"Press d For Moving Right");
     outtextxy(50,370,"Press c for Highscore");
      outtextxy(50,470,"Press z For Continue");
     getch();
     cleardevice();

barier();
     //x[0]=x[0]+10;
     setcolor(3);
 setfillstyle(SOLID_FILL,CYAN);
 pieslice(fx,fy,0,360,5);

}
void highscore()
{
    cleardevice();
    FILE *fp;
    char score2[50],str3[30];
    fp=fopen("ptr.txt","r");
    if(fp)
    {
        fgets(str3,30,fp);
        fgets(score2,50,fp);
        outtextxy(getmaxx()/2,getmaxy()/2,str3);
        outtextxy(getmaxx()/2,getmaxy()/2+50,score2);
    }
    else
        outtextxy(getmaxx()/2,getmaxy()/2,"No Records");
        outtextxy(getmaxx()/2,getmaxy()/2+100,"Press c for continue");
        if(getch()=='c')
        {
        cleardevice();
    barier();
    setcolor(3);
 setfillstyle(SOLID_FILL,CYAN);
 pieslice(fx,fy,0,360,5);
        }
     fclose(fp);
}
