#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>

class pixel1 {
    public:
        float x, y, length, dx, dy, height, width, X, Y;
        void DDA(float x1, float y1, float x2, float y2);
        void pattern();
        int sign(float value);
};

int pixel1::sign(float value) {
    if (value < 0)
        return -1;
    else if (value == 0)
        return 0;
    else
        return 1;
}

void pixel1::DDA(float x1, float y1, float x2, float y2) {
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    length = (dx > dy) ? dx : dy;

    dx = (x2 - x1) / length;
    dy = (y2 - y1) / length;

    x = x1 + 0.5 * sign(dx);
    y = y1 + 0.5 * sign(dy);

    for (int i = 0; i < length; i++) {
        delay(1);
        x += dx;
        y += dy;

        putpixel(x, y, WHITE);
    }
}

void pixel1::pattern() {
    cout << "\nEnter coordinates (X, Y): ";
    cin >> X >> Y;

    cout << "\nEnter width and height: ";
    cin >> width >> height;

    // Outer Rectangle
    DDA(X, Y, X + width, Y);               // Top edge
    DDA(X, Y, X, Y + height);              // Left edge
    DDA(X, Y + height, X + width, Y + height); // Bottom edge
    DDA(X + width, Y, X + width, Y + height);  // Right edge

    // Diagonal Cross Lines
    DDA(X, Y + height / 2, X + width / 2, Y);      // Top-left to center
    DDA(X, Y + height / 2, X + width / 2, Y + height); // Bottom-left to center
    DDA(X + width, Y + height / 2, X + width / 2, Y);  // Top-right to center
    DDA(X + width, Y + height / 2, X + width / 2, Y + height); // Bottom-right to center

    // Inner Rectangle
    DDA(X + width / 4, Y + height / 4, X + 3 * width / 4, Y + height / 4);     // Top edge
    DDA(X + width / 4, Y + 3 * height / 4, X + 3 * width / 4, Y + 3 * height / 4); // Bottom edge
    DDA(X + width / 4, Y + height / 4, X + width / 4, Y + 3 * height / 4);     // Left edge
    DDA(X + 3 * width / 4, Y + height / 4, X + 3 * width / 4, Y + 3 * height / 4); // Right edge
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    pixel1 s;
    s.pattern();
    delay(10000);
    
    getch();
    closegraph();
    return 0;
}
