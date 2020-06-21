
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
#include <dos.h>
float v0=0,x0, v, vs, dl=0, m=2,f0=0, k=200,l=100,w;
float x,xm, dt,t,T,tmax;
float x1, x1m, x10, v10, v1s,v1,m1=1;
int gd=DETECT, gm;
int i,j;

FILE *f; //Khai bao bien file

void main()
{
clrscr();
gd=DETECT;
initgraph(&gd,&gm,"C:\\TC\\BGI");

printf("Kich thuoc man hinh: %-5d x %5d\n",getmaxx(),getmaxy());
k=getmaxx()/(l);
printf("Ti le mo phong: %5.2f\n",k);
setcolor(BLUE);
rectangle(0,0,getmaxx(),getmaxy());
setcolor(MAGENTA);
line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
t=0;
w=sqrt(k/m); x0=dl;
T=2*3.14/w;
dt=T/200;
v10=-20;
x10=0.8*l;

//f=fopen("DULIEU.dat","wt"); //mo fi de ghi dung "w", doc file thi "r", "t" la file van ban;
//getch();
printf("Gia tri v0: %5.2f\n",v0);
printf("Gia tri x0: %5.2f\n",x0);
setcolor(BLACK);
 i=1;

 do
   {
  // v=v0+(-k*x0-alfa*v0+f0*cos(wf[1]*t+phi))/m*dt;
   v=v0+(-k*x0/m*dt);
   x=x0+v*dt;
   xm=k*x+getmaxx()/2;
   v1=v10;
   x1=x10+v10*dt;
   x1m=x1*k;

   setcolor(WHITE);
   setfillstyle(SOLID_FILL,GREEN);
   fillellipse(xm+5,getmaxy()/2-6,5,5);
   line(getmaxx()/4,getmaxy()/2-6,xm,getmaxy()/2-6);
   setfillstyle(SOLID_FILL,YELLOW);
   fillellipse(x1m+5,getmaxy()/2-6,5,5);
   delay(5);
   if (t==0) getch();

   setcolor(BLACK);
   setfillstyle(SOLID_FILL,BLACK);
   fillellipse(xm+5,getmaxy()/2-6,5,5);
   line(getmaxx()/4,getmaxy()/2-6,xm,getmaxy()/2-6);
   fillellipse(x1m+5,getmaxy()/2-6,5,5);

   putpixel(i/4,getmaxy()/8+xm/4,GREEN);
   putpixel(i/4,getmaxy()/1.5+v*k/8,CYAN);

   if (abs(xm-x1m)<10)
     {
     vs=((m-m1)*v+2*m1*v10)/(m+m1);
     v1s=((m1-m)*v10+2*m*v)/(m+m1);
     v=vs;
     v1=v1s;
     //t=0;
     }

   i=i+1;
   t=t+dt;
   x0=x;
   v0=v;
   x10=x1;
   v10=v1;
   //v10=v1;
   if (x1m+5>getmaxx()) v10=-v10;
   }
  while (!kbhit());
getch();

}
