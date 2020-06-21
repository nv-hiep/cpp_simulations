// Bai Chuyen Dong NGANG .. chuyen dong trong Khong kHi + Ma Sat

#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#define pi 3.14159362
#define n 200

void main()
{
  clrscr();
  int gd=DETECT,gm;
  int x,y;
  int dx;
  int r=10;
  //float t,dt;
  //putpixel(x,y,GREEN);
  //lineto(x,y);
  //fillellipse(x,y,1,1); */
  float m,k,F0,w=2*pi/20,phi=0.0;
  //float x0,x1,v1;
  float t,tt,dt,tmin=0.0,tmax=20.0,dtt;
  float xmin,xmax,vmin,vmax, xt[201],vt[201];
  int i,j;
  dt=(tmax-tmin)/n;
  xmax=-10e38;vmin=1e38;vmax=-vmin;
  m=1.0;k=-0.1;F0=10;t=0.0;
  //x0=0;v0=10;
  xt[1]=0; vt[1]=10;
  xt[0]=0; vt[0]=10;
  i=1;  xmin=xt[0];

  do
  {
    
    i++;
    vt[i]=vt[i-1]+((k*vt[i-1]+F0*cos(w*t+phi))/m)*dt;
    xt[i]=xt[i-1]+vt[i]*dt;
    if (xt[i]>xmax) xmax=xt[i];
    if (xt[i]<xmin) xmin=xt[i];
    if (vt[i]<vmin) vmin=vt[i];
    if (vt[i]>vmax) vmax=vt[i];
    t=t+dt;
  }
  while(t<=tmax);
  printf("xmin=%10.4f\n",xmin);
  printf("xmax=%10.4f\n",xmax);
  printf("vmin=%10.4f\n",vmin);
  printf("vmax=%10.4f\n",vmax);

  initgraph(&gd,&gm,"C:\\TC\\BGI");
  rectangle(xmin,0,xmax,getmaxy());
  line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
  x=0;y=getmaxy()/4;tt=0;dtt=40;j=0;
  do
  {
  j++;
  setcolor(BLACK);
  setfillstyle(SOLID_FILL,YELLOW);
  fillellipse(xt[j],y,r,r);
  //if (t==0) getch();
  delay(dtt);
  setfillstyle(SOLID_FILL,BLACK);
  fillellipse(xt[j],y,r,r);
 // x=x+dx;t=t+dt;
  }
  while (j<n);
  closegraph();

  getch();
  }
