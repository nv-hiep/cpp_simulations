/* Mo Phong Chuyen Dong Con Lac Don */



#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#define g 9.8

#define Radian 0.017453293 //1 do = 0.017453293 radian
#define PI 3.1415
#define BanKinh 5 //Ban kinh con lac
#define DelayTime 10
#define L 100 //Do dai con lac khi ve
int gDriver = DETECT, gMode, ErrorCode, MaxX, MaxY, *BitMap;
int x, y, x0, y0;

void KhoiTaoDoHoa()
{
	initgraph(&gDriver, &gMode, "C:\\TC\\BGI");
	rectangle(0,0,getmaxx(),getmaxy());
	ErrorCode = graphresult();

	if (ErrorCode != grOk)

	{
		printf("Graphics error: %s\n", grapherrormsg(ErrorCode));
		printf("Press any key to halt:");
		getch();
		exit(1);
	}
	
	MaxX = getmaxx();
	MaxY = getmaxy();
}

void VeConLac()
{
	setcolor(YELLOW);
	line(x0, y0, x, y);
	setfillstyle(SOLID_FILL, GREEN);
    setcolor(GREEN);
    fillellipse(x, y, BanKinh, BanKinh);
}

void XoaConLac()
{
	setcolor(BLACK);
	line(x0, y0, x, y);
	setfillstyle(SOLID_FILL, BLACK);
	setcolor(BLACK);
	fillellipse(x, y, BanKinh, BanKinh);
}

int main(void)
{
	float l, t = 0, FI, Alpha, Alpha0, w;
	
	/* Bat dau Khoi Tao Do Hoa */
	KhoiTaoDoHoa();
	/* KetThuc Khoi Tao Do Hoa */
	
	/* Bat dau Nhap so lieu */
	printf("1. Nhao vao chieu dai con lac (don vi Met): ");
	scanf("%f", &l);
	printf("2. Nhao vao bien do goc (don vi Do): ");
	scanf("%f", &Alpha0);
	printf("3. Nhao vao pha ban dau (Don vi Radian): ");
	scanf("%f", &FI);
	w = sqrt(g/l);
	/* KetThuc Nhap so lieu */
	
	/* Bat dau Ve thanh treo con lac */
	x0 = ceil(MaxX / 2);
	y0 = ceil(MaxY / 2 - 100);
	line(x0 - 10, y0, x0 + 10, y0);
	/* KetThuc Ve thanh treo con lac */

	/* Bat dau Mo phong chuyen dong cua con lac */
	do
	{
		Alpha = Alpha0*sin(w*t + FI);
		x = ceil(x0 + L*sin(Alpha*Radian));
		y = ceil(y0 + L*cos(Alpha*Radian));
		VeConLac();
		delay(DelayTime);
		XoaConLac();
	t = t + (float)DelayTime/1000;
	}
	while (!kbhit());
   /* KetThuc Mo phong chuyen dong cua con lac*/

	getch();
	closegraph();
	return 0;
}