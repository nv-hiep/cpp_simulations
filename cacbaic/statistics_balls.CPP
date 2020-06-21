//Bai BI TRANG + BI DEN: Tim xac suat...bieu dien tren DO THI

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <math.h>

# define nn 200

main ()
{
  int gd = DETECT, gm;
  float p[4];
  int A[9], B[8];
  int q1,q2,q3,q11,q22,q33;
  int dem,i,j,k;
  float x[4];
  int xm[4],ym[4];
  float kx,ky;
  int xmin,xmax,ymin,ymax;
  clrscr();
  randomize();
  for (i=0;i<=4;i++) p[i]=0;
  for (i=0;i<=nn;i++)
  {
    for (j=1;j<=5;j++) A[j]=0;
    for (k=6;k<=8;k++) A[k]=1;
    B[1]=0;B[2]=0;B[3]=1;B[4]=1;
    dem=0;

    q1=random(8)+1;B[5]=A[q1];

    do
    q2=random(8)+1; while (q1==q2);
    B[6]=A[q2];

    do
    q3=random(8)+1; while ((q1==q3)||(q2==q3));
    B[7]=A[q3];

    q11=random(7)+1; if (B[q11]==0) dem=dem+1;

    do
    q22=random(7)+1;
    while (q22==q11); if (B[q22]==0) dem=dem+1;

    do
    q33=random(7)+1;
    while ((q33==q11)||(q33==q22)); if (B[q33]==0) dem=dem+1;

    p[dem]=p[dem]+1;
    }

    for (i=0;i<=3;i++) p[i]=p[i]/nn;
    xmin=-1;
    xmax=4;
    for (i=0;i<=3;i++) x[i]=i;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
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



