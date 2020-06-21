#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>
#define n e-22
#define e 1.6e-19
#define Coulomb_const 9e9
#define r0 1.2e-15
#define A 198
main()
{int gd=DETECT, gm;
  float impact_param, radius;
  float q1,q2,m1,m2;
  float enery,f,fx,fy,r, x0, x1, y0,y1, v0, v1x, v0x, v0y, v1y, t, dt;
  float alpha_x, alpha_y;
  float xmin, xmax, ymin, ymax, k;
  int xm, ym, xm0, ym0, rm, i, mau;
  float temp, bmin, bmax, b, theta;
  randomize();
  m1=6.6e-27; m2=3.2e-25; q1=2*e; q2=79*e;
  radius=r0*pow(A,1.0/3);
  dt=1.e2-22;
  impact_param=10*radius;
  enery=7.63e-13;
  v0=sqrt(2*enery/m1);
  bmin=-impact_param;
  bmax=impact_param;
  xmin=100*radius; xmax=-xmin;
  initgraph(&gd,&gm,"C:\\TC\\BGI");
  rectangle(0,0,getmaxx(),getmaxy());
  k=getmaxy()/(xmax-xmin);
  for (i=1;i<=100;i++);
  {
    b=bmin+random(1000)/999.0*(bmax-bmin);
    x0=xmin, y0=b; v0x=v0; v0y=0;
    t=0;
    mau=random(15)+1;
    do{
    temp=x0*x0+y0*y0;
    f=Coulomb_const*q1*q2/temp;
    temp=sqrt(temp);
    fx=f*x0/temp; fy=f*y0/temp;
    v1x=v0x+fx/m1*dt; v1y=v0y+fy/m1*dt;
    x1=x0+v1x*dt; y1=y0+v1y*dt;
    xm=k*x1; ym=getmaxy()/2-k*y1;
    putpixel(xm,ym,mau);
    delay(10);
    t=t+dt;
    x0=x1; y0=y1, v0x=v1x, v0y=v1y;
    }while((x1<=0.5*xmax) || (x1>=xmin));
  }
outtextxy(getmaxx()/2,getmaxy()/2,"press any key to continue!");
getch();
closegraph();
}