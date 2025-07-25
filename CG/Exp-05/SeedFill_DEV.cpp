#include<iostream>
#include<graphics.h>

using namespace std;

class SeedFill {
    int x, y;

public:
    void seedFill(int, int, int, int);
    void drawPolygon();
};

void SeedFill::drawPolygon() {
    int p[20][2], i, n;

    // Draw axes
    line(320, 0, 320, 480);
    line(0, 240, 640, 240);

    cout << "\nEnter the number of vertices of the polygon: ";
    cin >> n;

    cout << "\nEnter all coordinates separated by a space:\n";
    for (i = 0; i < n; i++) {
        cin >> p[i][0] >> p[i][1];
        p[i][0] = 320 + p[i][0];
        p[i][1] = 240 - p[i][1];
    }

    p[i][0] = p[0][0];
    p[i][1] = p[0][1];

    // Draw the polygon
    for (i = 0; i < n; i++) {
        line(p[i][0], p[i][1], p[i + 1][0], p[i + 1][1]);
    }

    line(p[i][0], p[i][1], p[0][0], p[0][1]);
}

void SeedFill::seedFill(int x, int y, int oldColor, int newColor) {
    int color = getpixel(x, y);

    if (color == oldColor && color != newColor) {
        putpixel(x, y, newColor);
        delay(2);

        seedFill(x + 1, y, oldColor, newColor);
        seedFill(x - 1, y, oldColor, newColor);
        seedFill(x, y + 1, oldColor, newColor);
        seedFill(x, y - 1, oldColor, newColor);
    }
}

int main() {
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, NULL);

    SeedFill seedFillObject;
    seedFillObject.drawPolygon();

    int x, y;
    cout << "\nEnter an inside point of the polygon: ";
    cin >> x >> y;
    x = x + 320;
    y = 240 - y;

    int oldColor = getpixel(x, y);
    int newColor = 2;

    seedFillObject.seedFill(x, y, oldColor, newColor);

    delay(1000000);
    closegraph();

    return 0;
}
