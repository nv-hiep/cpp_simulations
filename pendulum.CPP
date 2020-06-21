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
float m,l,ttfi,ck,a,f,f0,ff,fi;
float tt0,tt,v,v0;
float x,y;
float xm,ym,ttm;
float t,tmax,dt;
float xmin,xmax,ymin,ymax,k,w;
int i;

w=1;m=2;l=3;ttfi=50;tt0=ttfi*pi/180;a=0;f0=0;v0=0;
f=sqrt(g/l)/2/pi;ck=1/f;ff=0.6*f;fi=0;
xmin=0;xmax=2.4*l;
ymin=0;ymax=2.4*l;
initgraph(&gd,&gm,"C:\\TC\\BGI");
rectangle(0,0,getmaxx(),getmaxy());
k=getmaxy()/(ymax-ymin);

line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
t=0;dt=0.01;i=0;
do
{
   v=v0-g*dt*sin(tt0)-(a*v0-f0*cos(ff*t+fi))*dt/m;
   tt=tt0+v*dt/l;
   x=l*sin(tt);
   y=l*cos(tt);
   xm=k*(x-xmin)+getmaxx()/2;
   ym=k*(y-ymin);
   setcolor(WHITE);
   line(getmaxx()/2,0,xm,ym);
   setcolor(BLACK);
   setfillstyle(SOLID_FILL,GREEN);
   fillellipse(xm,ym,10,10);
   if (t==0) getch();
   delay(20);
   setcolor(BLACK);
   //line(getmaxx()/2,0,xm,ym);
   setfillstyle(SOLID_FILL,BLACK);
   fillellipse(xm,ym,10,10);
   ttm=getmaxy()*0.5 - k*tt;
   putpixel(i/8,ttm,YELLOW);
   i=i+1;
   t=t+dt;
   tt0=tt;
   v0=v;
}while(!kbhit());
closegraph();
}