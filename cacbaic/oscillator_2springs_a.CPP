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
float r1,r2,w1,w2;
float x10,x1,v10,v1,y0,x20,x2,v20,v2;
float xmin,xmax,ymin,ymax,k;
float t,tmax,dt;
float xm,ym,xm1,ym1,xm2,wm1,wm2;
int test1,test2;
float l1m,l2m;
int i,j,count;

clrscr();
m1=1;m2=0.07*m1;r1=10;r2=1.3*r1;w1=r1/20;w2=2*w1;k1=20;k2=1.8*k1;
x10=0.7*r1;x20=x10+w1+r2;
v10=0;v20=0;

t=0;dt=0.0001;
test1=0;test2=0;ck1=0;ck2=0;

do
{
	v1=v10-k1/m1*(x10-r1)*dt+k2/m1*(x20-x10-w1-r2)*dt;
	v2=v20-k2/m2*(x20-x10-w1-r2)*dt;
	x1=x10+v1*dt;
	x2=x20+v2*dt;
	if(v1*v10<0) test1=1;
	if(v2*v20<0) test2=1;
	t=t+dt;
	v10=v1;v20=v2;
	x10=x1;x20=x2;
} while((test1==0)&&(test2==0));
if(test1==1) ck1=2*t;
if(test2==1) ck2=2*t;
if(ck1>ck2) dt=ck1/n; else dt=ck2/n;


initgraph(&gd,&gm,"C:\\TC\\BGI");
rectangle(0,0,getmaxx(),getmaxy());
//line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
ym=getmaxy()/4;
xmin=0;xmax=2*(r1+w1+r2+w2);k=getmaxx()/(xmax-xmin);
wm1=k*w1/2;wm2=k*w2/2;
x10=0.7*r1;x20=x10+w1+r2;
v10=0;v20=0;

t=0;
i=0;
do
{
	v1=v10-k1/m1*(x10-r1)*dt+k2/m1*(x20-x10-w1-r2)*dt;
	v2=v20-k2/m2*(x20-x10-w1-r2)*dt;
	x1=x10+v1*dt;xm1=k*(x1-xmin);
	x2=x20+v2*dt;xm2=k*(x2-xmin);

	l1=x1-r1;l1m=getmaxy()/2+k*l1;
	l2=x2-x1-w1-r2; l2m=getmaxy()/2+k*l2;


	setcolor(YELLOW);
	line(0,ym,xm1,ym);line(xm1,ym,xm2,ym);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,WHITE);
	fillellipse(xm1,ym,wm1,wm1);
	setfillstyle(SOLID_FILL,YELLOW);
	fillellipse(xm2,ym,wm2,wm2);
	if (t==0) getch();
	delay(10);
	line(0,ym,xm1,ym);line(xm1,ym,xm2,ym);
	fillellipse(xm1,ym,wm1,wm1);
	setfillstyle(SOLID_FILL,BLACK);
	fillellipse(xm1,ym,wm1,wm1);
	fillellipse(xm2,ym,wm2,wm2);

	putpixel(i/3,l1m,YELLOW);
	putpixel(i/3,l2m,WHITE);
	i=i+1;
	t=t+dt;
	v10=v1;v20=v2;
	x10=x1;x20=x2;
} while(!kbhit());
closegraph();
}

