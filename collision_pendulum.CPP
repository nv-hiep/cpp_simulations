#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#define g 9.8
#define r 3
#define pi 3.141


main ()
{
int gd=DETECT, gm;
float l,h,m1,m2;
float v0;
float m,l0,ttfi,ck,a,f,f0,ff,fi;
float tt0,tt,v;
float xcl,ycl;
//float ttm,w;
float x10,x1t,x20,x2t,y10,y1t,y20,y2t;
float vx10,vx1t,vy10,vy1t,vx20,vx2t,vy20,vy2t,vx1f,vx2f,vy1f,vy2f;
//float x1l0,x2l0,y1l0,y2l0,vx1l0,vy1l0,vx2l0,vy2l0;
//float x1lt,y1lt,vx1lt,vy1lt,x2lt,y2lt,vx2lt,vy2lt;
float xmin,xmax,ymin,ymax,k,kms;
float x[5],y[5];
float t,tmax1,tmax,dt;
float x1m,y1m,x2m,y2m,xm[5],ym[5];
int i,j,count;

clrscr();
//l0=5.0;ttfi=-45;tt0=ttfi*pi/180;a=0;f0=0;
//f=sqrt(g/l)/2/pi;ck=1/f;ff=0.6*f;fi=0;

l=10.0;h=10.0;m1=1;
v0=0;
//kms=0;

x[1]=0;x[2]=l;x[3]=l;x[4]=0;
y[1]=0;y[2]=0;y[3]=h;y[4]=h;

xmin=0;
xmax=15*l;
//vx2f*sqrt(2*h/g);
ymin=0;ymax=xmax;

initgraph(&gd,&gm,"C:\\TC\\BGI");
rectangle(0,0,getmaxx(),getmaxy());
k=getmaxy()/(xmax-xmin);
if ((ymax-ymin)>(xmax-xmin)) k=getmaxy()/(ymax-ymin);
//tinh toa do cua Ba`n va ve~ Ba`n
for (i=1;i<=4;i++)
{
xm[i]=k*(x[i]-xmin);
ym[i]=getmaxy()-k*(y[i]-ymin)+r;
}

//setcolor(YELLOW)
setlinestyle(SOLID_LINE,0,YELLOW);
//setcolor(YELLOW);
moveto(xm[1],ym[1]);
lineto(xm[2],ym[2]);
lineto(xm[3],ym[3]);
lineto(xm[4],ym[4]);
lineto(xm[1],ym[1]);

//Chuyen dong cua 2 vat
dt=0.01;

l0=5.0;ttfi=45;tt0=ttfi*pi/180;
f=sqrt(g/l)/2/pi;ck=1/f;ff=0.6*f;fi=0;
//x10=0;
vx10=v0;t=0;

do
{
	vx1t=vx10-g*dt*sin(tt0);
	tt=tt0+v*dt/l0;
	xcl=l0*sin(tt);
	ycl=l0*cos(tt);
	x1m=k*(xcl-xmin);
	y1m=k*(ycl-ymin);
	//x2m=k*l;
	//y2m=getmaxy();
	setcolor(WHITE);
	line(k*l,getmaxy()-k*(h+l0),x1m,y1m);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,GREEN);
	fillellipse(x1m,y1m,5,5);
	//fillellipse(x2m,y2m-r,5,5);
	if (t==0) getch();
	delay(10);
	setcolor(BLACK);
	line(k*l,getmaxy()-k*(h+l0),x1m,y1m);
	setfillstyle(SOLID_FILL,BLACK);
	fillellipse(x1m,y1m,5,5);
	//fillellipse(x2m,y2m-r,5,5);
	t=t+dt;
	vx10=vx1t;tt0=tt;

} while(!kbhit());

getch();
closegraph();

}
