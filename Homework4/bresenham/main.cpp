#include <GL/freeglut.h>
#include <iostream>

int x1 = 3, y1 = 7;
int x2 = 7, y2 = 0;

void pixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void line(int x1, int y1, int x2, int y2, int thickness)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int p = 2 * dy - dx;
    int dy2 = 2 * dy;
    int dyMinusdx = 2 * (dy - dx);
    int x, y;

    if(x1 > x2)
    {
        x = x2;
        y = y2;
        x2 = x1;
    }
    else
    {
        x = x1;
        y = y1;
    }

    for(int i = 0; i < thickness; i++)
    {
        pixel(x, y);
    }

    while(x < x2)
    {
        x++;
        if(p < 0)
            p += dy2;
        else
        {
            if((x2 > x1 && y2 > y1) || (x2 < x1 && y2 < y1))
                y++;
            else
                y--;
            p += dyMinusdx;
        }
        for(int i = 0; i < thickness; i++)
        {
            pixel(x, y);
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    line(x1, y1, x2, y2, 3);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Bresenham Line Algorithm");
    glOrtho(0, 10, 0, 10, -1, 1);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
