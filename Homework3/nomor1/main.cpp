#include <GL/freeglut.h>
#include <cmath>

int x1 = 4, y1_coord = 10, x2 = 15, y2 = 4;

void drawLine()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLineWidth(2.0);

    int dx = x2 - x1;
    int dy = y2 - y1_coord;
    int steps = std::abs(dx) > std::abs(dy) ? std::abs(dx) : std::abs(dy);
    float xIncrement = static_cast<float>(dx) / static_cast<float>(steps);
    float yIncrement = static_cast<float>(dy) / static_cast<float>(steps);
    float x = static_cast<float>(x1);
    float y = static_cast<float>(y1_coord);

    glBegin(GL_LINES);
    for(int i = 0; i <= steps; ++i)
    {
        glVertex2f(x, y);
        x += xIncrement;
        y += yIncrement;
    }
    glEnd();
    glFlush();
}

void display()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 20.0, 0.0, 20.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawLine();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("DDA Line Drawing");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
