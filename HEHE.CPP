#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.14159263

//void muiten(int x, int y, float t, float l, int c)
//void main ()
//{
 //int gd=DETECT,gm;
// float Q[3][3];
// int x0[3], y0[3];
// int x1[3], y1[3];
// int i;

// x0[1] = -l/sqrt(2); y0[1] = -l/sqrt(2);
// x0[2] = 0; y0[2] =0;
// x0[3] = -l/sqrt(2); y0[3] = l/sqrt(2);

 //Q[1][1] = cos(t); Q[1][2] = sin(t);
 //Q[2][1]= -sin(t); Q[2][2] = cos(t);
 //initgraph(&gd,&gm,"C:\\TC\\BGI");
 //rectangle(0,0,getmaxx(),getmaxy());
 //x=getmaxx()/2;
 //y=getmaxy()/2;

// for (i=1;i<=3;i++) {
//  x1[i] = cos(t)*x0[i]+sin(t)*y0[i] +x;
//  y1[i] = -sin(t)*x0[i]+cos(t)*y0[i] +y;
// }
//setlinestyle(SOLID_LINE,0,NORM_WIDTH);
//line(x0[1],y0[1],x0[2],y0[2]);
//line(x0[2],y0[2],x0[3],y0[3]);
//line(x0[1],y0[1],x0[3],y0[3]);
//moveto(x1[1],y1[1]);
//setcolor(c);
//lineto(x1[2],y1[2]);lineto(x1[3],y1[3]);lineto(x1[1],y1[1]);
//}

void main() {
  int gd=DETECT,gm;
  float p[9],k[9],xm[9],ym[9],t,l,e;
  float s=300,h,r=200,d=400,xmin,ymin;
 // float xmax,ymax;
  int x,y,c,i;
  //initgraph(&gd,&gm,"C:\\TC\\BGI");
 // rectangle(0,0,getmaxx(),getmaxy());
  //x=getmaxx()/2; y=getmaxy()/2;
  //c=10; l=10;
  //t=pi/4;
  //muiten(x,y,t,l,c);
  p[0]=s;k[0]=0;
  p[1]=0;k[1]=s;
  p[2]=d;k[2]=d+s;
  h=2*d+s-r;
  p[3]=r;k[3]=h;
  p[4]=-s;k[4]=0;
  p[5]=2*d-r;k[5]=h;
  p[6]=0;k[6]=-0.1*h;
  p[7]=d;k[7]=-0.1*h;
  p[8]=d;k[8]=1.1*h;
  p[9]=0;k[9]=1.1*h;
  initgraph(&gd,&gm,"C:\\TC\\BGI");
  rectangle(0,0,getmaxx(),getmaxy());
  //xmin=1e38; xmax=-xmin; ymin=1e38;ymax=-ymin;
  //for (i=0;i<=9;i++)
 // {
 //   if (p[i]<xmin) xmin=p[i];
 //   if (p[i]>xmax) xmax=p[i];
 //   if (k[i]<ymin) ymin=k[i];
 //   if (k[i]>xmax) ymax=k[i];
 // }
  //  e=getmaxy()/(ymax-ymin);
  //  if((xmax-xmin)>(ymax-ymin)) e=getmaxy()/(xmax-xmin);

 // for (i=0;i<=9;i++)
 // {
 //   xm[i]=e*(p[i]-xmin); ym[i]=e*(k[i]-ymin);
 // }

  setlinestyle(SOLID_LINE,0,THICK_WIDTH);
  setcolor(GREEN);
  line(xm[6],ym[6],xm[9],ym[9]);
  line(xm[7],ym[7],xm[8],ym[8]);
  //setcolor(RED);
  //line(s,0,0,s);
  //line(xm[1],ym[1],xm[2],ym[2]);
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