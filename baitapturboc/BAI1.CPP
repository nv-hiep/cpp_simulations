#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

void main()
{
int gd = DETECT, gm;
float h,d,w;
float x[7], y[7];
int xm[7], ym[7];
float k,xmin,ymin,xmax,ymax;
float a,b;
int i;
clrscr();
w=10;
h=7;
d=12;
x[1]= 0; y[1]=0;
x[2]=0; y[2]=2*h;
x[4]=w;y[4]=h-d;
x[5]=-0.1*w;y[5]=h;
x[6]=1.1*w; y[6]=h;
a=(y[4]-y[2])/(x[4]-x[2]);
b=y[4]-a*x[4];
y[3] = h; x[3]=(y[3]-b)/a;
initgraph(&gd,&gm,"C:\\TC\\BGI");
rectangle(0,0,getmaxx(),getmaxy());
xmin=1e38;xmax=-xmin;
ymin=1e38;ymax=-ymin;
for (i=1;i<=6;i++) {
if (x[i]<xmin) xmin=x[i];
if (x[i]>xmax) xmax=x[i];
if (y[i]<ymin) ymin=y[i];
if (y[i]>ymax) ymax=y[i];
}
ymin=ymin*1.1;
k=getmaxy()/(ymax-ymin);
if ((xmax-xmin)>(ymax-ymin)) k=getmaxy()/(xmax-xmin);

for (i=1;i<=6;i++)
{
xm[i]=k*(x[i]-xmin);
ym[i]=k*(y[i]-ymin);
}

setfillstyle(SOLID_FILL,YELLOW);
fillellipse(xm[1],ym[1],2,2);
setfillstyle(SOLID_FILL,GREEN);
fillellipse(xm[4],ym[4],2,2);
setlinestyle(SOLID_LINE,0,THICK_WIDTH);
setcolor(MAGENTA);
line(xm[5],ym[5],xm[6],ym[6]);
setlinestyle(SOLID_LINE,0,NORM_WIDTH);
setcolor(WHITE);
moveto(xm[1],ym[1]);lineto(xm[3],ym[3]);lineto(xm[4],ym[4]);
setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
line(xm[1],ym[1],xm[2],ym[2]);
line(xm[2],ym[2],xm[3],ym[3]);
getch();
closegraph();
settextjustify(CENTER_TEXT,CENTER_TEXT);
setcolor(YELLOW);

settextstyle(SMALL_FONT,7,2);

outtextxy(xm[1],ym[1]-10,"S");
outtextxy(xm[3],ym[3]+10,"M");
outtextxy(xm[4],ym[4]+10,"D");
}
