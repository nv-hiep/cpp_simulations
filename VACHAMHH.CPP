				   #include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#define g 9.8
#define r 3
#define q 3000

main ()
{
int gd=DETECT, gm;
float l,h,m1,m2;
float v0;
float x10,x1t,x20,x2t,y10,y1t,y20,y2t;
float vx10,vx1t,vy10,vy1t,vx20,vx2t,vy20,vy2t,vx1f,vx2f,vy1f,vy2f;
float xmin,xmax,ymin,ymax,k,kms;
float x[5],y[5];
float t,tmax1,tmax,dt;
float x1m[q],y1m[q],x2m[q],y2m[q],xm[5],ym[5];
int i,j,count;

clrscr();
l=10.0;h=10.0;dt=0.01;
m1=1;m2=2;v0=5;kms=0;
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
xmax=l+vx2f*sqrt(2*h/g);
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
dt=tmax/100;
x10=0;vx10=v0;t=0;x1m[0]=k*(x10-xmin);i=1;
x2m[0]=k*l;y1m[0]=k*h;x2m[0]=k*l;y2m[0]=k*h;
do
{
	vx1t=vx10-kms*vx10*dt/m1;
	x1t=x10+vx1t*dt;
	x1m[i]=k*(x1t-xmin);
	y1m[i]=k*h;
	x2m[i]=k*l;
	y2m[i]=k*h;
       //setcolor(BLACK);
	//setfillstyle(SOLID_FILL,GREEN);
	//fillellipse(x1m,y1m-r,5,5);
	//fillellipse(x2m,y2m-r,5,5);
	//if (t==0) getch();
	//delay(50);
	//setfillstyle(SOLID_FILL,BLACK);
	//fillellipse(x1m,y1m-r,5,5);
	//fillellipse(x2m,y2m-r,5,5);
	t=t+dt;
	x10=x1t;vx10=vx1t;
	i=i+1;
} while (x1t<l);
x10=l; x20=l;y10=h;y20=h;
vx10=vx1f;vy10=0;vx20=vx2f;

// Truong hop ca 2 vat cung bay ve phia Trc
if (vx1f>0)
{
	do
	{
	vx1t=vx10;x1t=x10+vx1t*dt;
	vy1t=vy10-g*dt;y1t=y10+vy1t*dt;
	vx2t=vx20; x2t=x20+vx2t*dt;
	vy2t=vy20-g*dt;y2t=y20+vy2t*dt;
	x1m[i]=k*(x1t-xmin);y1m[i]=getmaxy()-k*y1t;
	x2m[i]=k*(x2t-xmin);y2m[i]=getmaxy()-k*y2t;
	//setcolor(BLACK);
	//setfillstyle(SOLID_FILL,GREEN);
	//fillellipse(x1m,y1m-r,5,5);
	//fillellipse(x2m,y2m-r,5,5);
	t=t+dt;
	x10=x1t;y10=y1t;vx10=vx1t;vy10=vy1t;
	x20=x2t;y20=y2t;vx20=vx2t;vy20=vy2t;
	i=i+1;count=i;
	}while(x2t<3*l);
}
if (vx1f<0)
{
	do
	{
	vx1t=vx10-kms*vx10*dt/m1;x1t=x10+vx1t*dt;
	y1t=h;
	vx2t=vx20; x2t=x20+vx2t*dt;
	vy2t=vy20-g*dt;y2t=y20+vy2t*dt;
	x1m[i]=k*(x1t-xmin);y1m[i]=getmaxy()-k*y1t;
	x2m[i]=k*(x2t-xmin);y2m[i]=getmaxy()-k*y2t;
	//setcolor(BLACK);
	//setfillstyle(SOLID_FILL,GREEN);
	//fillellipse(x1m,y1m-r,5,5);
	//fillellipse(x2m,y2m-r,5,5);
	t=t+dt;
	x10=x1t;y10=y1t;vx10=vx1t;vy10=vy1t;
	x20=x2t;y20=y2t;vx20=vx2t;vy20=vy2t;
	i=i+1; count=i;
	} while(x2t<3*l);
}
  for (j=0;j<=count;j++)
  {
   setfillstyle(SOLID_FILL,YELLOW);setcolor(BLACK);
   fillellipse(x1m[j],y1m[j],3,3);
   setfillstyle(SOLID_FILL,GREEN);
   fillellipse(x2m[j],y2m[j],3,3);
   if (j==0) getch();
   delay(10);
   setfillstyle(SOLID_FILL,BLACK);fillellipse(x1m[j],y1m[j],3,3);
   setfillstyle(SOLID_FILL,BLACK);fillellipse(x2m[j],y2m[j],3,3);
   //if (j>3) putpixel(xm[j-3],ym[j-3],WHITE);
  }
getch();
closegraph();

}
