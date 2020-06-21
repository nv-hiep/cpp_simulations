#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#define g 9.8
#define pi 3.141
#define r 3
#define n 300

main ()
{
int gd=DETECT, gm;
float x0,y0,x1,y1,x2,y2;
float l1,l2,m1,m2,r1,r2;
float w01,w1,w02,w2,tt01,tt02,tt1,tt2;
float ck1,ck2;
float t,dt;
int x0m,y0m,x1m,y1m,x2m,y2m;
float k;
float tuso,mauso;
int i;
int tt1m,tt2m;
clrscr();
l1=1;l2=1;m1=1;m2=1;
r1=l1*0.05;
r2=l2*0.05;
tt01=45*pi/180;tt02=0;
w01=0;w02=0;
ck1=2*pi*sqrt(l1/g);ck2=2*pi*sqrt(l2/g);
if (ck1<ck2) dt=ck1/n; else dt=ck2/n;

initgraph(&gd,&gm,"C:\\TC\\BGI");
rectangle(0,0,getmaxx(),getmaxy());
line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
x0m=getmaxx()/2;y0m=0;
setcolor(YELLOW);
setlinestyle(SOLID_LINE,0,THICK_WIDTH);
line(x0m-5,y0m,x0m+5,y0m);
setlinestyle(SOLID_LINE,0,NORM_WIDTH);
k=getmaxy()/2/(l1+l2)*0.8;
t=0;
do
{
  tuso=-g*sin(tt01)*(2*m1+m2)-m2*g*sin(tt01-2*tt02)-2*sin(tt01-tt02)*m2*(w02*w02*l2 + w01*w01*l1*cos(tt01-tt02));
  mauso = l1*(2*m1+m2-m2*cos(2*tt01-2*tt02));
  w1=w01+tuso/mauso*dt;
  tt1=tt01+w1*dt;

  tuso=2*sin(tt01-tt02)*(w01*w01*l1*(m1+m2)+g*(m1+m2)*cos(tt01)+w02*w02*l2*m2*cos(tt01-tt02));
  mauso=l2*(2*m1+m2-m2*cos(2*tt01-2*tt02));
  w2=w02+tuso/mauso*dt;
  tt2=tt02+w2*dt;
  x1=l1*sin(tt1);
  y1=-l1*cos(tt1);
  x2=x1+l2*sin(tt2);
  y2=y1-l2*cos(tt2);
  x1m=k*x1+x0m;
  y1m=-k*y1;
  x2m=k*x2+x0m;
  y2m=-k*y2;
  setcolor(YELLOW);
  line(x0m,y0m,x1m,y1m);
  line(x1m,y1m,x2m,y2m);
  setcolor(BLACK);
  setfillstyle(SOLID_FILL,YELLOW);
  fillellipse(x1m,y1m,k*r1,k*r1);
  fillellipse(x2m,y2m,k*r2,k*r2);
  if (t==0) getch();
  delay(10);
  setcolor(BLACK);
  line(x0m,y0m,x1m,y1m);
  line(x1m,y1m,x2m,y2m);
  setfillstyle(SOLID_FILL,BLACK);
  fillellipse(x1m,y1m,k*r1,k*r1);
  fillellipse(x2m,y2m,k*r2,k*r2);
  t=t+dt;
  w01=w1;w02=w2;tt01=tt1;tt02=tt2;
  tt1m=k*tt1*0.5+400;
  tt2m=k*tt2*0.5+400;
  putpixel(i,tt1m,WHITE);
  putpixel(i,tt2m,WHITE);
  i=i+1;

}while(!kbhit());
getch();
closegraph();
}


