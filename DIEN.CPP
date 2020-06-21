#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>

void main()
{
float x,y,a,b;
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
rectangle(0,0,getmaxx(),getmaxy());
line(0,0,300,300);
getch();
}