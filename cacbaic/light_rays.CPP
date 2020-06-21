//Bai 2: duong di cua tia sang .... co cac MUI TEN

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.14159263

void muiten(float x, float y, float t, float l, int c)
//void main ()
{
 int gd=DETECT,gm;
 float Q[3][3];
 int x0[3], y0[3];
 int x1[3], y1[3];
 int i;

 x0[1] = -l/sqrt(2); y0[1] = -l/sqrt(2);
 x0[2] = 0; y0[2] =0;
 x0[3] = -l/sqrt(2); y0[3] = l/sqrt(2);

 //Q[1][1] = cos(t); Q[1][2] = sin(t);
 //Q[2][1]= -sin(t); Q[2][2] = cos(t);
 //initgraph(&gd,&gm,"C:\\TC\\BGI");

 for (i=1;i<=3;i++) {
  x1[i] = cos(t)*x0[i]+sin(t)*y0[i] +x;
  y1[i] = -sin(t)*x0[i]+cos(t)*y0[i] +y;
 }
//setlinestyle(SOLID_LINE,0,NORM_WIDTH);
//line(x0[1],y0[1],x0[2],y0[2]);
//line(x0[2],y0[2],x0[3],y0[3]);
//line(x0[1],y0[1],x0[3],y0[3]);
moveto(x1[1],y1[1]);
setcolor(c);
lineto(x1[2],y1[2]);lineto(x1[3],y1[3]);lineto(x1[1],y1[1]);
}

void main() {
  int gd=DETECT,gm;
  float p[14],k[14],xm[14],ym[14],t,l,e;
  float s=300,h,r=200,d=400,xmin,ymin;
  float xmax,ymax;
  float a[3],b[3];
  int x,y,c,i;
  //initgraph(&gd,&gm,"C:\\TC\\BGI");
  //rectangle(0,0,getmaxx(),getmaxy());
  //x=getmaxx()/2; y=getmaxy()/2;
  //c=10; l=10;
  //t=pi/4;
  //muiten(x,y,t,l,c);
  p[1]=s;k[1]=0;
  p[2]=0;k[2]=s;
  p[3]=d;k[3]=d+s;
  h=2*d+s-r;
  p[4]=r;k[4]=h;

  p[5]=-s;k[5]=0;
  p[6]=2*d-r;k[6]=h;
  p[7]=0;k[7]=-0.05*h;
  p[8]=d;k[8]=-0.05*h;
  p[9]=d;k[9]=1.05*h;
  p[10]=0;k[10]=1.05*h;
 //p[11]=s/2; k[11]=a*p[11]+b;
  a[1]=(k[2]-k[1])/(p[2]-p[1]);
  b[1]=k[2]-a[1]*p[2];
  p[11]=s/2;k[11]=a[1]*p[11]+b[1];

  a[2]=(k[3]-k[2])/(p[3]-p[2]);
  b[2]=k[3]-a[2]*p[3];
  p[12]=d/2;k[12]=a[2]*p[12]+b[2];

  a[3]=(k[4]-k[3])/(p[4]-p[3]);
  b[3]=k[4]-a[3]*p[4];
  p[13]=d/1.5;k[13]=a[3]*p[13]+b[3];

  //p[12]=d/2; k[12]=a*p[12]+b;
  //dgthang(p[3],k[3],p[4],k[4]);
  //p[13]=d*0.75;k[13]=a*p[13]+b;
  initgraph(&gd,&gm,"C:\\TC\\BGI");
  rectangle(0,0,getmaxx(),getmaxy());
  xmin=1e38; xmax=-xmin; ymin=1e38;ymax=-ymin;
  for (i=1;i<=13;i++)
  {
    if (p[i]<xmin) xmin=p[i];
    if (p[i]>xmax) xmax=p[i];
    if (k[i]<ymin) ymin=k[i];
    if (k[i]>xmax) ymax=k[i];
  }
    e=getmaxy()/(ymax-ymin);
    if((xmax-xmin)>(ymax-ymin)) e=getmaxy()/(xmax-xmin);

  for (i=1;i<=13;i++)
  {
    xm[i]=e*(p[i]-xmin); ym[i]=e*(k[i]-ymin);
  }

  setlinestyle(SOLID_LINE,0,THICK_WIDTH);
  setcolor(RED);
  line(xm[7],ym[7],xm[10],ym[10]);
  line(xm[8],ym[8],xm[9],ym[9]);
  setcolor(GREEN);
  setlinestyle(SOLID_LINE,0,NORM_WIDTH);
  line(xm[1],ym[1],xm[2],ym[2]);
  line(xm[2],ym[2],xm[3],ym[3]);
  line(xm[3],ym[3],xm[4],ym[4]);
  setcolor(YELLOW);
  setlinestyle(DASHED_LINE,0,NORM_WIDTH);
  line(xm[1],ym[1],xm[5],ym[5]);
  line(xm[2],ym[2],xm[5],ym[5]);
  line(xm[4],ym[4],xm[6],ym[6]);
  line(xm[3],ym[3],xm[6],ym[6]);

  setlinestyle(SOLID_LINE,0,THICK_WIDTH);
  //line(xm[11],ym[11],xm[10],ym[10]);
  muiten(xm[11],ym[11],1.25*pi,e*20,7);
  muiten(xm[12],ym[12],1.75*pi,e*20,7);
  muiten(xm[13],ym[13],1.25*pi,e*20,7);

  getch();


}
//setlinestyle(SOLID_LINE,0,THICK_WIDTH);
//setcolor(GREEN);
//line(x0[1],y0[1],x0[2],y0[2]);
//line(x0[2],y0[2],x0[3],y0[3]);
//line(x0[1],y0[1],x0[3],y0[3]);
//getch();
//closegraph();
//}