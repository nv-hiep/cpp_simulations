#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
#define g 9.8
#define n 200

void main()
{
 float m=1,h0=10,v1,y0,y1,v0;
 float ymax,t,tmax,dt,ky,xm,ym;
 float k=0.2;
 int gm,gd;
 clrscr();
 dt=0.0001;
 t=0;y0=h0;v0=20;
 ymax=-1e38;
 do
 {
  v1=v0+((-m*g-k*v0)/m)*dt;
  y1=y0+v1*dt;
  if (y1>ymax) ymax=y1;
  t=t+dt;y0=y1;v0=v1;
  }
  while(v1>0);
tmax=t;ymax=y1;
//printf("tmax=%10.3f giay\n",tmax);
//printf("hmax=%10.3f m",ymax);
gd = DETECT;
initgraph(&gd,&gm,"C:\\TC\\BGI");
rectangle(0,0,getmaxx(),getmaxy());
dt=tmax/n;
y0=h0;
v0=20;
ky=getmaxy()/ymax*0.8;
t=0;
do
{
 v1=v0+((-m*g-k*v0)/m)*dt;
 y1=y0+v1*dt;
 xm=getmaxy()/2;
 ym=getmaxy()-ky*y1;
 setfillstyle(SOLID_FILL,YELLOW);
 setcolor(BLACK);
 fillellipse(xm,ym,10,10);
 //if (t==0) getch();
 delay(5);
 setfillstyle(SOLID_FILL,BLACK);
 fillellipse(xm,ym,10,10);
 if (y1<=0) v1=-v1;
 t=t+dt;
 v0=v1;y0=y1;
}
while (!kbhit());
closegraph();
getch();
}