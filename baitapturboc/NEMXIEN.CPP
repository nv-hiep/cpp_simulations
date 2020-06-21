#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
#define g 9.81
#define n 2000
#define pi 3.14159263

main()
{
 float m=1,h0=10,v1x,v1y,y0,y1,v0,v0y,v0x,t1;
 float ymax,t,tmax,dt,dtt,a=pi/6,x1,x0,xmax,xm[n+1],ym[n+1];
 float k=0.2,kk,k1=2;
 int i,j,gm,gd;

 clrscr();
 //a=pi/4;
 dt=0.0001;
 t=0;y0=0;v0=10;x0=0;
 v0y=v0*sin(a);
 v0x=v0*cos(a);
 ymax=-1e38; t1=40;
 do
 {
  v1x=v0x+((-k/m)*v0x)*dt;
  x1=x0+v1x*dt;
  v1y=v0y+((-m*g-k*v0y)/m)*dt;
  y1=y0+v1y*dt;
  if (y1<=0)
  {tmax=t;v1y=-v1y;}

  if (y1>ymax) ymax=y1;
  t=t+dt;
  v0x=v1x; x0=x1;
  v0y=v1y; y0=y1;
  }
  while(t<=t1);

xmax=x1;
//printf("ymax la: %10.3f\n",ymax);
//printf("xmax la: %10.3f\n",xmax);
//printf("tmax la: %10.3f\n",tmax);


gd=DETECT;
initgraph(&gd,&gm,"C:\\TC\\BGI");
rectangle(0,0,getmaxx(),getmaxy());
kk=getmaxx()/xmax;
 if (ymax>xmax) kk=getmaxy()/ymax;
 dtt=tmax/n;
 //a=pi/4;
 t=0;y0=0;v0=10;x0=0;
 v0y=v0*sin(a);
 v0x=v0*cos(a);

 //kk=kk+0.9;

 xm[0]=x0*kk;ym[0]=getmaxy()-kk*y0;
 i=0;
do
 {
  v1x=v0x+((-k1/m)*v0x)*dtt;
  x1=x0+v1x*dtt;
  v1y=v0y+((-m*g-k1*v0y)/m)*dtt;
  y1=y0+v1y*dtt;

 xm[i+1]=kk*x1; ym[i+1]=getmaxy()-10*kk*y1;


 if (y1<=0) v1y=-v1y;
  t=t+dtt;
  v0x=v1x; x0=x1;
  v0y=v1y; y0=y1;
 i++;

}
  while(t<20);
  for (j=0;j<=i;j++)
  {
   setfillstyle(SOLID_FILL,YELLOW);setcolor(BLACK);
   fillellipse(xm[j],ym[j],3,3);
   if (j==0) getch();
   delay(5);
   setfillstyle(SOLID_FILL,BLACK);fillellipse(xm[j],ym[j],3,3);
   if (j>3) putpixel(xm[j-3],ym[j-3],WHITE);
  }


closegraph();
getch();
}