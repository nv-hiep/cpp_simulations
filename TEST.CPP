#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#define np0 101

 FILE *fp;
 float a0[4],a1[4],da[4];
 float x[np0],y[np0];
 float JA[4,4],JB[4];
 float khisq0,khisq[1];
 float dh[4];
 int i,j,k,np;

void ve()
{int gd=DETECT,gm;
 float xmin,xmax,ymin,ymax,kx,ky;
 int xm[np0],ym[np0],i;
 xmin=1e38; xmax=-xmin; ymin=1e38; ymax=-ymin;
 for(i=1;i<=np;i++)
 {
  if (x[i]<xmin) xmin=x[i];
  if (x[i]>xmax) xmax=x[i];
  if (y[i]<ymin) ymin=y[i];
  if (y[i]>ymax) ymax=y[i];
 }
 initgraph(&gd,&gm,"C:\\TC\\BGI"); rectangle(0,0,getmaxx(),getmaxy());
 kx=getmaxx()/(xmax-xmin); ky=getmaxy()/(ymax-ymin)*0.8;
 for (i=1;i<=np;i++)
 {
   xm[i]=kx*(x[i]-xmin);
   ym[i]=getmaxy()-ky*(y[i]-ymin);
   fillellipse(xm[i],ym[i],1,1);
 }
 getch();
 closegraph();
}
void docfile()
{
  int i;
  fp=fopen("GAUSS.txt","rt");
 for (i=0;i<=100;i++)
 {fscanf(fp,"%f%f\n",&x[i],&y[i]); }
 fclose(fp);
}

main()
{ clrscr(); np=np0-1;
  docfile(); ve();
}
