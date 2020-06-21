#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#define n 500
#define pi 3.14
#define g 9.8
#define r 10
main()
{
int gd=DETECT,gm;
float l,m,chuki,alpha,tanso,f0,tansof,phi,wf,w;
float teta,teta0,v0,v;
float x,y;
int xm,ym,tetam;
float xmax,xmin,ymax,ymin,k;
int i;
float t,dt;

clrscr();
m=1;l=10;teta0=70;
teta0=teta0*pi/180;
alpha=0.0;f0=0;


tanso=sqrt(g/l)/2/pi;   chuki=1/tanso;
tansof=0.8*tanso;       wf=2*pi*tansof;
phi=0;
xmin=-l;xmax=l;
ymin=xmin;ymax=xmax;
initgraph (&gd,&gm,"C:\\TC\\BGI");
rectangle (0,0,getmaxx(),getmaxy());
k=getmaxy()/(xmax-xmin);
line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
t=0;dt=0.01;i=0;v0=0;tetam=0;
do
{
v=v0+(-g*sin(teta))*dt;
teta=teta0+v*dt/l;
x=l*sin(teta);
y=l*cos(teta);
xm=k*(x-xmin)+getmaxx()/2;
ym=k*(y-ymin)+getmaxy()/2;
setcolor(WHITE);
line(getmaxx()/2,getmaxy()/2,xm,ym);
setcolor(BLACK);
setfillstyle(SOLID_FILL,GREEN);
fillellipse(xm,ym,10,10);
if (t==0) getch();
delay(15);
line(getmaxx()/2,getmaxy()/2,xm,ym);
setfillstyle(SOLID_FILL,BLACK);
fillellipse(xm,ym,10,10);
//tetam=getmaxy()*0.75-k*teta;
//putpixel(i/10,tetam,YELLOW);
//i=i+1;
t=t+dt;teta0=teta;v0=v;
}while(!kbhit());
getch();
closegraph();
}