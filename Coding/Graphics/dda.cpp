#include <iostream>
#include <winbgm.h>
#include <math.h>
#include  <dos.h>


using namespace std;

main(){
	float x0,y0,x1,y1,Xinc,Yinc,dx,dy,x,y;
	int steps;
	initgraph(&gd,&gm,"~/Coding-master/Coding/Graphics/bgi");
	dx=x1-x0;
	dy=y1-y0;
	steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
	Xinc=dx/(steps);
	Yinc=dy/steps;
	x=x0;
	y=y0;
	for(int i=0;i<=steps;i++){
		putpixel(x,y,5);
		x=x+Xinc;
		y=y+Yinc;
		delay(100);
	}
	delay(1000);
	closegraph();
}