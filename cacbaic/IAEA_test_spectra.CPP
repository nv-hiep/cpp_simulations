// This program is used for reading the IAEA test spectra
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
#include <ctype.h>
#include <string.h>
 #include <alloc.h>
#define max_channel 5000
 int gd=DETECT,gm;
 int x[max_channel],y[max_channel],yt[max_channel];
 int xm,ym;
 float xmin,xmax,ymin,ymax,kx,ky;
 int i,j;
 int sokenh;
 int xd,xc;
 int xp,yp;
 int temp;
 int number_c;
 float ytb,khisq0,khisq,do_tron;
 int kd,kc,npoint;
 char c;
 char ch[25],*ch1,*ch2;
 char title[100];
void contro(int xp,int mau);
void lam_tron(int kd,int kc,int npoint,int y[],int yt[]);
void main()
{ FILE *f;

 clrscr();
 f=fopen("C:\\TC\\TEST04.DAT","rt");
//fscanf(f,"%s\n",title);
 i=-1;
 while (!feof(f))
 { for (j=1;j<=10;j++)
    {i=i+1; x[i]=i;
     if (j<10)  fscanf(f,"%7d",&y[i]);
     if (j==10) fscanf(f,"%7d\n",&y[i]);
//     printf("%7d   %7d\n",x[i],y[i]);
    }
//    getch();
}
 sokenh=i;
 fclose(f);
 kd=1;kc=sokenh;npoint=15;
 lam_tron(kd,kc,npoint,y,yt);
   initgraph(&gd,&gm,"C:\\TC\\BGI");
   rectangle(0,0,getmaxx(),getmaxy());
   line(0,getmaxy()/2.5,getmaxx(),getmaxy()/2.5);
   line(0,getmaxy()/1.25,getmaxx(),getmaxy()/1.25);
   xmin=1.; xmax=sokenh;
   ymin=0.; ymax=0.;
   for(i=1;i<=sokenh;i++)
   {if(y[i]>ymax) ymax=y[i];}
   kx=getmaxx()/(xmax-xmin);
   ky=getmaxy()/2.6/(ymax-ymin);

   for (i=1;i<=sokenh;i++)
   {xm=kx*x[i];
    ym=getmaxy()/2.5-ky*(y[i]-ymin);
    if(i==1) moveto(xm,ym);
    if(i>1) lineto(xm,ym);
//    putpixel(xm,ym,WHITE);
	}
    getch();

    for (i=1;i<=sokenh;i++)
     {xm=kx*x[i];
      ym=getmaxy()/1.25-ky*(yt[i]-ymin);
      if(i==1) moveto (xm,ym);
      if(i>1) lineto(xm,ym);
//    putpixel(xm,ym,WHITE);
	}
    getch();
	xp=10.;
	contro(xp,0);
	do
	{ c=getch();
	  number_c=toascii(c);
	  if(number_c==114)
	    {contro(xp,0); xp=xp+1; contro(xp,10);}
	  if(number_c==108)
	    {contro(xp,0); xp=xp-1; contro(xp,10);}
	} while (number_c!=13);
	xd=xp;

	do
	{ c=getch();
	  number_c=toascii(c);
	  if(number_c==114)
	    {contro(xp,0); xp=xp+1; contro(xp,10);}
	  if(number_c==108)
	    {contro(xp,0); xp=xp-1; contro(xp,10);}
	} while (number_c!=13);
	xc=xp;

	if(xc<xd) {temp=xd;xd=xc;xc=temp;}
// tinh khisquare c?a pho ban dau tu xd den xc
	ytb=0;
	for (i=xd;i<=xc;i++)
	   { ytb=ytb+y[i];}
	ytb=ytb/(xc-xd);
	khisq0=0.;
	for (i=xd;i<=xc;i++)
	    {khisq0=khisq+(y[i]-ytb)*(y[i]-ytb);}
// tinh khisquare c?a pho lam tron tu xd den xc
	ytb=0;
	for (i=xd;i<=xc;i++)
	   { ytb=ytb+i;}
	ytb=ytb/(xc-xd);
	khisq=0.;
	for (i=xd;i<=xc;i++)
	    {khisq=khisq+(yt[i]-ytb)*(yt[i]-ytb);}
	do_tron= abs(khisq-khisq0)/khisq0*100.;
	ch1= "do lam tron :";
	itoa(do_tron,ch2,6);
	strcpy(ch,ch1);
	strcat(ch,ch2);
	outtextxy(350,415,ch);
	getch();

   closegraph();
}


 void lam_tron(int kd,int kc,int npoint,int y[],int yt[])
 {
 float temp,norm;
 float w[8];
 int i,j;
 for(i=kd;i<=kc;i++)
    {yt[i]=y[i];}
 if(npoint==5)
    {w[0]=17;w[1]=12;w[2]=-3;norm=35;}
 if(npoint==7)
    {w[0]=7;w[1]=6;w[2]=3;w[3]=-2;norm=21;}
 if(npoint==9)
    {w[0]=59;w[1]=54;w[2]=39;w[3]=14;w[4]=-21;norm=231;}
 if(npoint==11)
     {w[0]=89;w[1]=84;w[2]=69;w[3]=44;w[4]=9;w[5]=-36;norm=429;}
 if(npoint==13)
     {w[0]=25;w[1]=24;w[2]=21;w[3]=16;w[4]=9;w[5]=0;w[6]=-11;norm=143;}
 if(npoint==15)
     {w[0]=167;w[1]=162;w[2]=147;w[3]=122;w[4]=87;w[5]=42;w[6]=-13;w[7]=-78;norm=1105;}
 for(i=kd+npoint/2;i<=kc-npoint/2;i++)
    {temp=0.;
     for(j=-npoint/2;j<=npoint/2;j++)
     { if(j<0) temp=temp+w[-j]*y[i+j];
       if(j>=0) temp=temp+w[j]*y[i+j];}
	yt[i]=temp/norm;}
 }


  void contro(int xp,int mau)
   {
   char text[25];
   char *s1,*s2,*s3;
   ym=getmaxy()/2.5-ky*(y[xp]-ymin);
   xm=kx*(xp-xmin);
   setcolor(mau);
   line(xm,ym-2,xm,ym-30);
   setfillstyle(SOLID_FILL,BLACK);
   s3="Channel :";
   strcpy(text,s3);
   itoa(xp,s1,6);
   strcat(text,s1);
   itoa(y[xp],s2,6);
   strcat(text,"   counts :");
   strcat(text,s2);
   outtextxy(350,400,text);
   }