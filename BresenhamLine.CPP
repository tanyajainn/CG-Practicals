#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#include <graphics.h>

struct Point {
	int x;
	int y;
};

void bresenham(Point p1, Point p2) {
	int dx, dy, d;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;

	d = (2 * dy) - dx;

	Point temp = p1;

	while (temp.x <= p2.x) {
		if (d <= 0) {
			temp.x++;
			d = d + (2 * dy);
		} else {
			temp.x++;
			temp.y++;
			d = d + (2 * (dy - dx));
		}
		putpixel(temp.x + getmaxx()/2, temp.y + getmaxy()/2, WHITE);
		delay(10);
	}
}

void main() {
	clrscr();

	Point p1, p2;
	cout<<"Enter coordinates for initial point: ";
	cin>>p1.x>>p1.y;
	cout<<"Enter coordinates for final point: ";
	cin>>p2.x>>p2.y;

	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	int centerX = getmaxx()/2;
	int centerY = getmaxy()/2;

	for (int i=0; i <= getmaxx(); i++) {
		putpixel(i, centerY, WHITE);
	}

	for (int j=0; j <= getmaxy(); j++) {
		putpixel(centerX, j, WHITE);
	}

	bresenham(p1, p2);

	getch();
	closegraph();
}
