#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#define g 9.8
#define r 3


main ()
{
int gd=DETECT, gm;
float l,h,m1,m2;
float v0;
float x10,x1t,x20,x2t,y10,y1t,y20,y2t;
float vx10,vx1t,vy10,vy1t,vx20,vx2t,vy20,vy2t,vx1f,vx2f,vy1f,vy2f;
float x1l0,x2l0,y1l0,y2l0,vx1l0,vy1l0,vx2l0,vy2l0;
float x1lt,y1lt,vx1lt,vy1lt,x2lt,y2lt,vx2lt,vy2lt;
float xmin,xmax,ymin,ymax,k,kms;
float x[5],y[5];
float t,tmax1,tmax,dt;
float x1m,y1m,x2m,y2m,xm[5],ym[5];
int i,j,count;

clrscr();
l=10.0;h=10.0;dt=0.01;
m1=1;m2=0.5;v0=10;kms=0;
x[1]=0;x[2]=l;x[3]=l;x[4]=0;
y[1]=0;y[2]=0;y[3]=h;y[4]=h;
x10=0;vx10=v0;t=0;
do
{
vx1t=vx10+(kms/m1)*vx10*dt;
x1t=x10+vx1t*dt;
t=t+dt;
x10=x1t;vx10=vx1t;
} while (x1t<l);

tmax1=t;

tmax=tmax1+sqrt(2*h/g);
vx2f=2*m1*vx1t/(m1+m2);
vx1f=(m1-m2)*vx1t/(m1+m2);

xmin=0;
xmax=l+5*vx2f*sqrt(2*h/g);
ymin=0;ymax=2*h;

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
x10=0;vx10=v0;t=0;
x20=l;vx20=0;

x1l0=l;x2l0=l;y1l0=h;y2l0=h;
vx1l0=vx1f;vy1l0=0;vx2l0=vx2f;vy2l0=0;
do
{
	if (t<(l/v0))
	{
	vx1t=vx10-kms*vx10*dt/m1;
	x1t=x10+vx1t*dt;
	x1m=k*(x1t-xmin);
	y1m=getmaxy()-k*h;
	x2m=k*l;
	y2m=getmaxy()-k*h;
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,GREEN);
	fillellipse(x1m,y1m-r,5,5);
	fillellipse(x2m,y2m-r,5,5);
	if (t==0) getch();
	delay(10);
	setfillstyle(SOLID_FILL,BLACK);
	fillellipse(x1m,y1m-r,5,5);
	fillellipse(x2m,y2m-r,5,5);
	t=t+dt;
	vx10=vx1t;x10=x1t;
       // x1l0=x1lt;y1l0=y1lt;vx1l0=vx1lt;vy1l0=vy1lt;
	//x2l0=x2lt;y2l0=y2lt;vx2l0=vx2lt;vy2l0=vy2lt;
	}
	if (t>=(l/v0))
	{
		if (vx1f>0)
		{
		vx1lt=vx1l0;x1lt=x1l0+vx1lt*dt;
		vy1lt=vy1l0-g*dt;y1lt=y1l0+vy1lt*dt;
		vx2lt=vx2l0; x2lt=x2l0+vx2lt*dt;
		vy2lt=vy2l0-g*dt;y2lt=y2l0+vy2lt*dt;
		if (y1lt<=0) vy1lt=-vy1lt;
		if (y2lt<=0) vy2lt=-vy2lt;
		x1m=k*(x1lt-xmin);y1m=getmaxy()-k*y1lt;
		x2m=k*(x2lt-xmin);y2m=getmaxy()-k*y2lt;
		setcolor(BLACK);
		setfillstyle(SOLID_FILL,GREEN);
		fillellipse(x1m,y1m-r,5,5);
		fillellipse(x2m,y2m-r,5,5);
		if (t==0) getch();
		delay(10);
		setfillstyle(SOLID_FILL,BLACK);
		fillellipse(x1m,y1m-r,5,5);
		fillellipse(x2m,y2m-r,5,5);
		t=t+dt;
		//vx10=vx1t;x10=x1t;
		x1l0=x1lt;y1l0=y1lt;vx1l0=vx1lt;vy1l0=vy1lt;
		x2l0=x2lt;y2l0=y2lt;vx2l0=vx2lt;vy2l0=vy2lt;
		}

		if (vx1f<0)
		{
		vx1lt=vx1l0-kms*vx1l0*dt/m1;x1lt=x1l0+vx1lt*dt;
		y1lt=h;
		vx2lt=vx2l0; x2lt=x2l0+vx2lt*dt;
		vy2lt=vy2l0-g*dt;y2lt=y2l0+vy2lt*dt;
		if (y1lt<=0) vy1lt=-vy1lt;
		if (y2lt<=0) vy2lt=-vy2lt;
		x1m=k*(x1lt-xmin);y1m=getmaxy()-k*y1lt;
		x2m=k*(x2lt-xmin);y2m=getmaxy()-k*y2lt;
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,GREEN);
	fillellipse(x1m,y1m-r,5,5);
	fillellipse(x2m,y2m-r,5,5);
	if (t==0) getch();
	delay(10);
	setfillstyle(SOLID_FILL,BLACK);
	fillellipse(x1m,y1m-r,5,5);
	fillellipse(x2m,y2m-r,5,5);
	t=t+dt;
	//vx10=vx1t;x10=x1t;
	x1l0=x1lt;y1l0=y1lt;vx1l0=vx1lt;vy1l0=vy1lt;
	x2l0=x2lt;y2l0=y2lt;vx2l0=vx2lt;vy2l0=vy2lt;

		}
	}


} while(!kbhit());

getch();
closegraph();

}
