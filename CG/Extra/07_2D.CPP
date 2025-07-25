#include <iostream.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#define M 10

class graph
{
    private:
        int A[M][M], ans[M][M], trans[3][3], color, n;
        float rotat[2][2], scal[2][2];

    public:
        graph();
        void drawline(float, float, float, float);
        void polynomial();
        int sign(float);
        void Showpoly();
        void translation();
        void Scaling();
        void Rotation();
        void Display();
        void tryi();
};

graph::graph()
{
    color = RED;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
                trans[i][j] = 1;
            else
                trans[i][j] = 0;
        }
    }

    scal[0][0] = 1;
    scal[0][1] = 0;
    scal[1][0] = 0;
    scal[1][1] = 1;
}

void graph::tryi()
{
    int t;
    cout << "Enter rotation angle value in degree : ";
    cin >> t;
    cout << sin(t * 180 / 3.14) << " ";
}

void graph::drawline(float x1, float y1, float x2, float y2)
{
    int dx, dy, length, x, y;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (dx >= dy)
        length = dx;
    else
        length = dy;

    dx = (x2 - x1) / length;
    dy = (y2 - y1) / length;
    x = x1 + 0.5 * sign(dx);
    y = y1 + 0.5 * sign(dy);

    int i = 0;
    while (i <= length)
    {
        x = x + dx;
        y = y + dy;
        putpixel(x, y, color);
        i = i + 1;
    }
}

int graph::sign(float a)
{
    if (a < 0)
        return -1;
    else if (a == 0)
        return 0;
    else
        return 1;
}

void graph::polynomial()
{
    cout << "Enter number of vertex: ";
    cin >> n;

    cout << "\n -->> please Enter vertex coordinates Serially: \n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nX coordinate and Y coordinate for " << i + 1 << " point: ";
        cin >> A[i][0] >> A[i][1];
        A[i][2] = 1;
    }
}

void graph::Showpoly()
{
    cleardevice();  // Clear the screen before drawing

    color = RED;

    for (int i = 0; i < n - 1; i++)
    {
        line(A[i][0], A[i][1], A[i + 1][0], A[i + 1][1]);
        cout << A[i][0] << " " << A[i][1] << " " << A[i + 1][0] << " " << A[i + 1][1] << "\n";
    }

    line(A[0][0], A[0][1], A[n - 1][0], A[n - 1][1]);

    delay(3000);  // Pause for 3 seconds to allow viewing of the output
}

void graph::translation()
{
    int tx, ty;
    color = GREEN;

    // Move text away from the graphics area
    outtextxy(10, 10, "Enter translation value tx, ty: ");
    gotoxy(40, 2); // Move cursor away for input
    cin >> tx >> ty;

    trans[2][0] = tx;
    trans[2][1] = ty;

    cleardevice();  // Clear the screen before drawing the transformed polygon

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ans[i][j] = A[i][0] * trans[0][j] + A[i][1] * trans[1][j] + A[i][2] * trans[2][j];
        }
    }

    Display();
}

void graph::Scaling()
{
    int sx, sy;
    color = YELLOW;

    // Move text away from the graphics area
    outtextxy(10, 10, "Enter Scaling value sx, sy: ");
    gotoxy(40, 2); // Move cursor away for input
    cin >> sx >> sy;

    scal[0][0] = sx;
    scal[1][1] = sy;

    cleardevice();  // Clear the screen before drawing the scaled polygon

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ans[i][j] = A[i][0] * scal[0][j] + A[i][1] * scal[1][j];
        }
    }

    Display();
}

void graph::Rotation()
{
    int t;
    cout << "Enter rotation angle value in degree: ";
    cin >> t;

    rotat[0][0] = cos(t * 3.14 / 180);
    rotat[0][1] = -sin(t * 3.14 / 180);
    rotat[1][0] = sin(t * 3.14 / 180);
    rotat[1][1] = cos(t * 3.14 / 180);

    cleardevice();  // Clear the screen before drawing the rotated polygon

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ans[i][j] = A[i][0] * rotat[0][j] + A[i][1] * rotat[1][j];
        }
    }

    Display();
}

void graph::Display()
{
    cleardevice();  // Clear the screen before displaying the new polygon

    for (int i = 0; i < n - 1; i++)
    {
        line(ans[i][0], ans[i][1], ans[i + 1][0], ans[i + 1][1]);
    }

    line(ans[0][0], ans[0][1], ans[n - 1][0], ans[n - 1][1]);

    delay(3000);  // Pause for 3 seconds to allow viewing of the output
}

int main()
{
    graph obj;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    int ch;

    while (1)
    {
        cleardevice();  // Clear the graphics screen for a fresh interface each time
        outtextxy(10, 10, "Enter choice:\n 1. Create polynomial\n 2. Show polynomial\n");
        outtextxy(10, 30, " 3. Translation\n 4. Scaling\n 5. Rotation\n 6. Exit program");
        gotoxy(5, 8); // Move cursor to take user input
        cout << "----> choice: ";
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case 1:
            obj.polynomial();
            break;

        case 2:
            obj.Showpoly();
            break;

        case 3:
            obj.translation();
            break;

        case 4:
            obj.Scaling();
            break;

        case 5:
            obj.Rotation();
            break;

        case 6:
            closegraph();
            return 0;

        default:
            outtextxy(10, 100, "Wrong Choice, Please Try Again...");
            delay(2000);  // Pause to show the message for 2 seconds
        }
    }
}
