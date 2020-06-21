//dao dong cua 2 lo xo
//f1=-k1*l1+k2*l2;
//f2=-k2*l2;l1=x1-r1;l2=x2-x1-w1-r2;
//m1*x1''=-k1(x1-r1)+k2(x2-x1-w1-r2);
//m2*x2''=-k2(x2-x1-w1-r2);
//x1,x2 la vi tri tinh theo canh phia trai cua cac vat
//v1,v2 la van toc cua cac vat
//f1,f2 la luc td len cac vat
//m1,m2 la khoi luong cua cac vat
//w1,w2 do day
//k1,k2 do cung
//r1,r2 chieu dai lo xo tai vtcb

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
float l1,l2,m1,m2,k1,k2,a,fn,wn,fi,w01,w02,ck1,ck2;
float r10,r20,r1,r2,w1,w2,ycb1,ycb2;
float x10,x1,v10,v1,y0,x20,x2,v20,v2,y10,y20,y1,y2;
float xmin,xmax,ymin,ymax,k;
float t,tmax,dt;
float xm,ym,xm1,ym1,ym2,xm2,wm1,wm2;
int test1,test2;
float l1m,l2m;
int i,j,count;

clrscr();
m1=100;m2=8;r10=10;r20=1.3*r10;w1=r10/10;w2=0.5*w1;k1=100;k2=2.8*k1;
//x10=0.7*r1;x20=x10+w1+r2;
r1=r10+(m1+m2)*g/k1;ycb1=r1;
r2=r20+m2*g/k2;ycb2=ycb1+w1+r2;
y10=0.7*r10; y20=y10+w1+r2;
v10=0;v20=0;

t=0;dt=0.001;
test1=0;test2=0;ck1=0;ck2=0;

do
{
	v1=v10-k1/m1*(y10-r10)*dt+k2/m1*(y20-y10-w1-r20)*dt+g*dt+m2/m1*g*dt;
	v2=v20-k2/m2*(y20-y10-w1-r20)*dt+g*dt;
	y1=y10+v1*dt;
	y2=y20+v2*dt;
	if(v1*v10<0) test1=1;
	if(v2*v20<0) test2=1;
	t=t+dt;
	v10=v1;v20=v2;
	y10=y1;y20=y2;
} while((test1==0)&&(test2==0));
if(test1==1) ck1=2*t;
if(test2==1) ck2=2*t;
if(ck1>ck2) dt=ck1/n; else dt=ck2/n;


initgraph(&gd,&gm,"C:\\TC\\BGI");
rectangle(0,0,getmaxx(),getmaxy());
//line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
xm=getmaxx()/2;
ymin=0;ymax=2*(r1+w1+r2+w2);k=getmaxy()/(ymax-ymin);
wm1=k*w1/2;wm2=k*w2/2;
y10=0.7*r10;y20=y10+w1+r2;
v10=0;v20=0;

t=0;
i=0;
do
{
	v1=v10-k1/m1*(y10-r10)*dt+k2/m1*(y20-y10-w1-r20)*dt+g*dt+m2/m1*g*dt;
	v2=v20-k2/m2*(y20-y10-w1-r20)*dt+g*dt;
	y1=y10+v1*dt;
	y2=y20+v2*dt;

	ym1=k*(y1-ymin);
	ym2=k*(y2-ymin);

	l1=y1-r10;l1m=getmaxx()/2+k*l1;
	l2=y2-y1-w1-r20;l2m=getmaxx()/2+k*l2;


	setcolor(GREEN);
	line(xm,0,xm,ym1);
	setcolor(RED);
	line(xm,ym1,xm,ym2);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,WHITE);
	fillellipse(xm,ym1,wm1,wm1);
	setfillstyle(SOLID_FILL,YELLOW);
	fillellipse(xm,ym2,wm2,wm2);
	if (t==0) getch();
	delay(10);
	line(xm,0,xm,ym1);line(xm,ym1,xm,ym2);
	setfillstyle(SOLID_FILL,BLACK);
	fillellipse(xm,ym1,wm1,wm1);
	fillellipse(xm,ym2,wm2,wm2);

	putpixel(i/3,l1m,YELLOW);
	putpixel(i/3,l2m,WHITE);
	i=i+1;
	t=t+dt;
	v10=v1;v20=v2;
	y10=y1;y20=y2;
} while(!kbhit());
closegraph();
}

