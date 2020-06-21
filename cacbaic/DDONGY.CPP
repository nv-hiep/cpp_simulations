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
float l,m,dc,a,fn,wn,fi,w0,ck;
float x0,x1,v0,v1,ycb,y0,y1;
float xmin,xmax,ymin,ymax,k;
float x[5],y[5];
float t,tmax,dt;
float xm,ym,xm1,ym1;
int i,j,count;
FILE *f;

clrscr();
m=1;l=10;dc=100;a=0;fn=15;w0=sqrt(dc/m);
ck=2*pi/w0;wn=1*w0;
fi=0;dt=ck/n;
initgraph(&gd,&gm,"C:\\TC\\BGI");
rectangle(0,0,getmaxx(),getmaxy());
line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
xm=getmaxx()/2;
ymin=0;ymax=2*l;k=getmaxy()*0.5/(ymax-ymin);
ycb=l+m*g/dc;
y0=ycb-0.2*ycb;v0=0;t=0;i=0;
do
{
	v1=v0+(-dc*(y0-l)+m*g)*dt/m;
	y1=y0+v1*dt;
	ym=k*(y1);
	setcolor(YELLOW);line(xm,0,xm,ym);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,YELLOW);
	fillellipse(xm,ym,10,10);
	if (t==0) getch();
	delay(5);
	line(xm,0,xm,ym);
	setfillstyle(SOLID_FILL,BLACK);
	fillellipse(xm,ym,10,10);
	i=i+1;
	putpixel(i/6,ym+getmaxy()/2,WHITE);
	t=t+dt;y0=y1;v0=v1;
} while(!kbhit());
getch();
closegraph();
}
