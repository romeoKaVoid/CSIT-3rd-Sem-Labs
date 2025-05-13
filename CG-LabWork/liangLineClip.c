#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <dos.h>

int main() {
    int i, gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x1, y1, x2, y2, xmin, xmax, ymin, ymax;
    int xx1, xx2, yy1, yy2, dx, dy;
    float t1, t2, p[4], q[4], temp;

    // Input Clipping Window and Line
    printf("Enter xMin and yMin: ");
    scanf("%d%d", &xmin, &ymin);
    printf("Enter xMax and yMax: ");
    scanf("%d%d", &xmax, &ymax);
    printf("Enter the initial points (x1, y1): ");
    scanf("%d%d", &x1, &y1);
    printf("Enter the final points (x2, y2): ");
    scanf("%d%d", &x2, &y2);

    // Draw the clipping window and original line
    rectangle(xmin, ymin, xmax, ymax);
    line(x1, y1, x2, y2);

    // Calculate differences
    dx = x2 - x1;
    dy = y2 - y1;

    // Compute p and q values
    p[0] = -dx; q[0] = x1 - xmin;  // Left
    p[1] = dx;  q[1] = xmax - x1;  // Right
    p[2] = -dy; q[2] = y1 - ymin;  // Bottom
    p[3] = dy;  q[3] = ymax - y1;  // Top

    // Initialize t1 and t2
    t1 = 0;
    t2 = 1;

    // Compute intersections
    for (i = 0; i < 4; i++) {
        if (p[i] != 0) {  // Avoid division by zero
            temp = (float)q[i] / p[i];

            if (p[i] < 0) {  // Entry condition
                if (temp > t1)
                    t1 = temp;
            } else {  // Exit condition (p[i] > 0)
                if (temp < t2)
                    t2 = temp;
            }
        } else if (q[i] < 0) {  // Fully outside case
            printf("Line is completely outside.\n");
            return 0;  // No need to draw anything
        }
    }

    // Check if line is inside
    if (t1 < t2) {
        xx1 = x1 + t1 * dx;
        yy1 = y1 + t1 * dy;
        xx2 = x1 + t2 * dx;
        yy2 = y1 + t2 * dy;

        // Clear previous drawings
        delay(1000);
        clearviewport();
        rectangle(xmin, ymin, xmax, ymax);
        line(xx1, yy1, xx2, yy2);  // Draw clipped line
    } else {
        printf("Line is outside the clipping window.\n");
    }

    // Display text
    outtextxy(25, 25, "Line Clipping Algorithm : Krishna");
    
    delay(7000);
    getch();
    // closegraph();
    return 0;
}
