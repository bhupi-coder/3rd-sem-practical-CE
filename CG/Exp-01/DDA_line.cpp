#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>

class pixel {
    public:
        float x, y, length, dx, dy;
        int p;
};

class pixel1 : public pixel {
    public:
        void DDA(float, float, float, float);
        void bresen(float, float, float, float);
        int sign(float);
};

int pixel1::sign(float x) {
    if (x < 0)
        return -1;
    else if (x == 0)
        return 0;
    else
        return 1;
}

void pixel1::DDA(float x1, float y1, float x2, float y2) {
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (dx > dy)
        length = dx;
    else
        length = dy;

    dx = (x2 - x1) / length;
    dy = (y2 - y1) / length;

    x = x1 + 0.5 * sign(dx);
    y = y1 + 0.5 * sign(dy);
    
    line(0, 240, 640, 240);  // X-axis
    line(320, 0, 320, 480);  // Y-axis
    
    for (int i = 0; i < length; i++) {
        x = x + dx;
        y = y + dy;
        putpixel(x, y, WHITE);
    }
}

void pixel1::bresen(float x1, float y1, float x2, float y2) {
    int temp, exchange_flag = 0;
    
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    
    int s1 = sign(x2 - x1);
    int s2 = sign(y2 - y1);
    
    x = x1;
    y = y1;
    
    if (dy > dx) {
        temp = dx;
        dx = dy;
        dy = temp;
        exchange_flag = 1;
    } else {
        exchange_flag = 0;
    }
    
    p = 2 * dy - dx;
    
    line(0, 240, 640, 240);  // X-axis
    line(320, 0, 320, 480);  // Y-axis
    
    int i = 0;
    while (i <= dx) {
        putpixel(abs(x), abs(y), 15);
        
        if (p >= 0) {
            if (exchange_flag == 1)
                x = x + s1;
            else
                y = y + s2;
            p = p - 2 * dx;
        }
        
        if (exchange_flag == 1)
            y = y + s2;
        else
            x = x + s1;
        
        p = p + 2 * dy;
        i++;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    pixel1 s;
    float x1, y1, x2, y2;
    char ans;
    int ch;
    
do {
    cout << "\n**** MENU ****";
    cout << "\n1. Draw Line using DDA Algorithm";
    cout << "\n2. Draw Line using Bresenham's Algorithm";
    cout << "\n3. Exit";
    cout << "\nPlease select an option (1-3): ";
    cin >> ch;

    switch (ch) {
        case 1:
            cout << "\nEnter the coordinates of the line (x1, y1, x2, y2): ";
            cin >> x1 >> y1 >> x2 >> y2;
            x1 += 320; y1 = 240 - y1;
            x2 += 320; y2 = 240 - y2;
            s.DDA(x1, y1, x2, y2);
            break;

        case 2:
            cout << "\nEnter the coordinates of the line (x1, y1, x2, y2): ";
            cin >> x1 >> y1 >> x2 >> y2;
            x1 += 320; y1 = 240 - y1;
            x2 += 320; y2 = 240 - y2;
            s.bresen(x1, y1, x2, y2);
            break;

        case 3:
            cout << "\nExiting the program.";
            break;

        default:
            cout << "\nInvalid option. Please select a valid option (1-3).";
    }

    if (ch != 3) {
        cout << "\nWould you like to perform another operation? (y/n): ";
        cin >> ans;
    }
} while (ans == 'y' || ans == 'Y');

    getch();
    closegraph();
    return 0;
}

