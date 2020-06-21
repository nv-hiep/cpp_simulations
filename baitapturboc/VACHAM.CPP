#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
#define n 200

void main()
{
 float m1=1,m2=100,v1i=5,v2i=0;
 float vcm,v1icm,v1fcm,v2fcm,v2icm;
 float v1f,v2f;
 clrscr();
 vcm=(m1*v1i+m2*v2i)/(m1+m2);
 v1icm=v1i-vcm;
 v2icm=v2i-vcm;
 v1fcm=-v1icm;v2fcm-v2icm;
 v1f=v1fcm+vcm;v2f=v2fcm+vcm;
 printf("Vat 1 sau vc",v1f);
 printf("Vat 2 sau vc",v2f);
 getch();
}
