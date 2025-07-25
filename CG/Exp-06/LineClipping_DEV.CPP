#include <iostream>
#include <graphics.h>
#include <cmath> // For floating-point calculations
using namespace std;

static int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
int xmin, ymin, xmax, ymax;

int getcode(int x, int y) {
    int code = 0;
    if (y > ymax) code |= TOP;
    if (y < ymin) code |= BOTTOM;
    if (x < xmin) code |= LEFT;
    if (x > xmax) code |= RIGHT;
    return code;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    cout << "Enter the window's minimum (xmin, ymin) and maximum (xmax, ymax) coordinates: ";
    cin >> xmin >> ymin >> xmax >> ymax;

    // Draw the clipping window
    rectangle(xmin, ymin, xmax, ymax);

    int x1, y1, x2, y2;
    cout << "Enter the line's endpoints (x1, y1, x2, y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    // Draw the initial line
    line(x1, y1, x2, y2);
    getch();

    int outcode1 = getcode(x1, y1);
    int outcode2 = getcode(x2, y2);
    bool accept = false;

    while (true) {
        if (outcode1 == 0 && outcode2 == 0) {
            // Line is completely inside the clipping window
            accept = true;
            break;
        } else if ((outcode1 & outcode2) != 0) {
            // Line is completely outside the clipping window
            break;
        } else {
            // Line is partially inside
            int x, y;
            int temp = (outcode1 != 0) ? outcode1 : outcode2;

            float m = static_cast<float>(y2 - y1) / (x2 - x1);

            if (temp & TOP) {
                x = x1 + (ymax - y1) / m;
                y = ymax;
            } else if (temp & BOTTOM) {
                x = x1 + (ymin - y1) / m;
                y = ymin;
            } else if (temp & LEFT) {
                x = xmin;
                y = y1 + m * (xmin - x1);
            } else if (temp & RIGHT) {
                x = xmax;
                y = y1 + m * (xmax - x1);
            }

            if (temp == outcode1) {
                x1 = x;
                y1 = y;
                outcode1 = getcode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                outcode2 = getcode(x2, y2);
            }
        }
    }

    cout << "After clipping:";
    if (accept) {
        cleardevice();
        rectangle(xmin, ymin, xmax, ymax);
        line(x1, y1, x2, y2);
    } else {
        cout << "Line is completely outside the clipping window.";
    }

    getch();
    closegraph();
    return 0;
}

