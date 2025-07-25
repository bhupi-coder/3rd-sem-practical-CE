#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
using namespace std;

class A {
    public:
        int x, y, x1, y1, r, d;
};

class B : public A {
    public:
        void getdata();
        void draw();
};

void B::getdata() {
    cout << "\nEnter center coordinates (x, y): ";
    cin >> x1 >> y1;
    x1 = x1 + 320;
    y1 = 240 - y1;

    cout << "\nEnter radius of circle: ";
    cin >> r;
}

void B::draw() {
    d = 3 - 2 * r;  // d is the decision parameter
    x = 0;
    y = r;

    line(320, 0, 320, 480);  // Y-axis
    line(0, 240, 640, 240);  // X-axis

    do {
        putpixel(x1 + x, y1 + y, 15);
        putpixel(x1 + x, y1 - y, 15);
        putpixel(x1 + y, y1 + x, 15);
        putpixel(x1 + y, y1 - x, 15);
        putpixel(x1 - x, y1 + y, 15);
        putpixel(x1 - x, y1 - y, 15);
        putpixel(x1 - y, y1 + x, 15);
        putpixel(x1 - y, y1 - x, 15);

        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x = x + 1;
    } while (x < y);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    B obj1;
    obj1.getdata();
    obj1.draw();

    getch();
    closegraph();
    return 0;
}
