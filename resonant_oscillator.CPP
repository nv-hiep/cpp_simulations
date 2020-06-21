#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#define g 9.8
#define pi 3.141569
#define r 3
#define n 300

main ()
{
int gd=DETECT, gm;
float l,m,dc,a,fn,fi,w0,ck;
float x0,x1,v0,v1;
float xmin,xmax,ymin,ymax,kx,ky;
float t,tmax,dt,wmin,wmax;
float xm,ym,xm1,ym1,xcd[500],wn[500],xmcd[500],wmn[500];
int i,j;
FILE *f;

clrscr();
m=1;l=10;dc=100;a=0;fn=15;w0=sqrt(dc/m);
ck=2*pi/w0;wmin=0.2*w0;wmax=1.8*w0;wn[0]=wmin;
fi=0;dt=0.001;i=0;


f=fopen("conghuong.dat","wt");

do
{    xcd[i]=-1e38;
     x0=-0.2*l;v0=0;t=0;
	do
	{
		v1=v0+(-dc*x0-a*v0+fn*sin(wn[i]*t+fi))*dt/m;
		x1=x0+v1*dt;
		if(x1>xcd[i]) xcd[i]=x1;
		t=t+dt;v0=v1;x0=x1;
	}   while(t<25*ck);
	fprintf(f,"%8.3f %8.3f \n", wn[i],xcd[i]);
	i=i+1;
	wn[i]=wn[i-1]+(wmax-wmin)/501;

}while(wn[i]<=wmax);
fclose(f);

ymax=-1e38;ymin=1e38;
for (j=0;j<=500;j++)
{
if (xcd[j]>ymax) ymax=xcd[j];
if (xcd[j]<ymin) ymin=xcd[j];
}

initgraph(&gd,&gm,"C:\\TC\\BGI");
rectangle(0,0,getmaxx(),getmaxy());

kx=getmaxx()/(wmax-wmin);ky=getmaxy()/ymax;

for (j=0;j<=500;j++)
{
    wmn[j]=kx*(wn[j]-wmin);
    xmcd[j]=getmaxy()-ky*xcd[j];
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(wmn[j],xmcd[j],r,r);
}
getch();
closegraph();
}
