#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#define n 200
#define r 5

main ()
{
int gd=DETECT, gm;
float m1,m2,v1i,v2i,v1f,v2f,v1ci,v2ci,v1cf,v2cf,vc;
float xmin,xmax,kx,t,dt,t1,t2,x01,x1,x02,x2;
int xm1,ym1,xm2,ym2;
clrscr();
m1=1;v1i=0;m2=50;v2i=-6;x01=0;x02=20;

//Tinh van toc cua 2 Vat trc va sau va cham
vc=(m1*v1i+m2*v2i)/(m1+m2);
v1ci=v1i-vc; v2ci=v2i-vc;
v1cf=-v1ci; v2cf=-v2ci;
v1f=v1cf+vc; v2f=v2cf+vc;

// tinh thoi gian trc va cham
t1=abs(x01-x02)/abs(v1i-v2i);
t2=3*t1;
dt=t2/n;
t=0;
xmin=1e38; xmax=-xmin;

do
{
	if (t<t1) 
		{
		 x1=x01+v1i*dt;
		 x2=x02+v2i*dt;
		}

	if(t>=t1)
		{
		 x1=x01+v1f*dt;
		 x2=x02+v2f*dt;
		}
	if (x1<xmin) xmin=x1; if (x1>xmax) xmax=x1;
	if (x2<xmin) xmin=x2; if (x2>xmax) xmax=x2;
	t=t+dt;
	x01=x1;x02=x2;
} while (t<=t2);

initgraph(&gd,&gm,"C:\\TC\\BGI");
rectangle(0,0,getmaxx(),getmaxy());
kx=getmaxx()/(xmax-xmin);
x01=0;x02=20;t=0;
do
{
	if (t<t1) 
		{
		 x1=x01+v1i*dt;
		 x2=x02+v2i*dt;
		}

	if(t>=t1)
		{
		 x1=x01+v1f*dt;
		 x2=x02+v2f*dt;
		}
xm1=kx*(x1-xmin);
ym1=getmaxy()/2;
xm2=kx*(x2-xmin);
ym2=getmaxy()/2;

setcolor(BLACK);
setfillstyle(SOLID_FILL,YELLOW);
fillellipse(xm1,ym1,r,r);
setfillstyle(SOLID_FILL,GREEN);
fillellipse(xm2,ym2,r,r);
if (t==0) getch();
delay(50);
setfillstyle(SOLID_FILL,BLACK);
fillellipse(xm1,ym1,r,r);
fillellipse(xm2,ym2,r,r);
t=t+dt;
x01=x1;x02=x2;
} while(!kbhit());
closegraph();
}

 