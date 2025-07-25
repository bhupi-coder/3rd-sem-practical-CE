#include <graphics.h>
#include <conio.h>  // For getch()
#include <dos.h>    // For delay()

int main() {
    int gd = DETECT, gm;
    int i, maxx, midy;
 
    /* initialize graphic mode */
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    /* maximum pixel in horizontal axis */
    maxx = getmaxx();
    /* mid pixel in vertical axis */
    midy = getmaxy() / 2;
 
    for (i = 0; i < maxx - 120; i = i + 4) {
        /* clears screen */
        cleardevice();
 
        /* draw a white road */
        setcolor(WHITE);
        line(0, midy + 37, maxx, midy + 37);
 
        /* Draw Car */
        setcolor(YELLOW);
 
        line(i, midy + 23, i, midy);
        line(i, midy, 40 + i, midy - 20);
        line(40 + i, midy - 20, 80 + i, midy - 20);
        line(80 + i, midy - 20, 100 + i, midy);
        line(100 + i, midy, 120 + i, midy);
        line(120 + i, midy, 120 + i, midy + 23);
        line(0 + i, midy + 23, 18 + i, midy + 23);
        arc(30 + i, midy + 23, 0, 180, 12);
        line(42 + i, midy + 23, 78 + i, midy + 23);
        arc(90 + i, midy + 23, 0, 180, 12);
        line(102 + i, midy + 23, 120 + i, midy + 23);
 
        /* Draw Roof */
        line(28 + i, midy, 43 + i, midy - 15);
        line(43 + i, midy - 15, 57 + i, midy - 15);
        line(57 + i, midy - 15, 57 + i, midy);
        line(57 + i, midy, 28 + i, midy);
        line(62 + i, midy - 15, 77 + i, midy - 15);
        line(77 + i, midy - 15, 92 + i, midy);
        line(92 + i, midy, 62 + i, midy);
        line(62 + i, midy, 62 + i, midy - 15);
 
        /* Draw Wheels */
        setcolor(BLUE);
        circle(30 + i, midy + 25, 9);
        circle(90 + i, midy + 25, 9);
        floodfill(30 + i, midy + 25, BLUE);
        floodfill(90 + i, midy + 25, BLUE);
 
        /* Add delay of 0.05 seconds */
        delay(50);
    }
 
    getch();
    closegraph();
    getch();  // Keep the screen open after closing graphics
    return 0;
}
