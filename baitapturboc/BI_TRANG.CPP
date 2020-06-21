#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>

# define nn 200

main ()
{
  int gd = DETECT, gm;
  float p[4];
  int A[9], B[8];
  int q1,q2,q3;
  int dem,i;
  float x[4];
  int xm[4],ym[4];
  float kx,ky;
  int xmin,xmax,ymin,ymax;
  clrscr();
  randomize();
  for (i=0;i<=4;i++) p[i]=0;
  for (i=0;i<=nn;i++)
  {
    for (i=1;i<=5;i++) A[i]=0;
    for (i=6;i<=8;i++) A[i]=1;
    B[1]=0;B[2]=0;B[3]=1;B[4]=1;
    dem=0;

    q1=random(8)+1;B[5]=A[q1];

    do
    q2=random(8)+1; while (q1==q2);
    B[6]=A[q2];

    do
    q3=random(8)+1; while ((q1==q3)||(q2==q3));
    B[7]=A[q3];

    q1=random(7)+1; if (B[q1]==0) dem=dem+1;

    do
    q2=random(7)+1;
    while (q1==q2); if (B[q2]==0) dem=dem+1;

    do
    q3=random(7)+1;
    while ((q1==q3)||(q2==q3)); if (B[q3]==0) dem=dem+1;

    p[dem]=p[dem]+1;
    }

    for (i=0;i<=3;i++) p[i]=p[i]/nn;
    xmin=-1;
    xmax=4;
    for (i=0;i<=3;i++) x[i]=i;
    initgraph(&gd,&gm,"C:\\TC\BGI");
    rectangle(0,0,getmaxx(),getmaxy());
    kx=getmaxx()/(xmax-xmin); ky=getmaxy();
    for (i=0;i<=3;i++)
    {
      xm[i]=kx*(x[i]-xmin);
      ym[i]=getmaxy()-ky*p[i];
      bar (xm[i]-5,ym[i],xm[i]+5,getmaxy());
    }
    getch();

}



