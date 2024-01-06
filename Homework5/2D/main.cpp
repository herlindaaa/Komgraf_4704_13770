/*#include <GL/glut.h>
#include <math.h>

float rotate_angle = 0.0f;
float scale_factor = 1.0f;
float translate_x = 0.0f;
float translate_y = 0.0f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(rotate_angle, 0.0f, 0.0f, 1.0f);
    glScalef(scale_factor, scale_factor, 1.0f);
    glTranslatef(translate_x, translate_y, 0.0f);
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(-0.5f, -0.5f);
        glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(0.5f, -0.5f);
        glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(0.0f, 0.5f);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
}

void specialKeys(int key, int x, int y)
{
    if(key == GLUT_KEY_RIGHT) rotate_angle += 5.0f;
    else if(key == GLUT_KEY_LEFT) rotate_angle -= 5.0f;

    else if (key == GLUT_KEY_UP) { scale_factor += 0.1f; if(scale_factor > 2.0f) scale_factor = 2.0f; }
    else if (key == GLUT_KEY_DOWN) { scale_factor -= 0.1f; if(scale_factor < 0.5f) scale_factor = 0.5f; }

    else if (key == GLUT_KEY_HOME) translate_x += 0.1f;
    else if (key == GLUT_KEY_END) translate_x -= 0.1f;
    else if (key == GLUT_KEY_PAGE_UP) translate_y += 0.1f;
    else if (key == GLUT_KEY_PAGE_DOWN) translate_y -= 0.1f;

    glutPostRedisplay();
}

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0f, 1.0f, -1.0f, 1.0f);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Transformasi 2D");

    init();

    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);

    glutMainLoop();
    return 1;
}*/

#include <GL/glut.h>
#include <cmath>

float angle = 0.0f;
float scale_factor = 1.0f;
float translation_x = 0.0f, translation_y = 0.0f;
bool mirror = false;

void drawPoint(float x, float y) {
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void drawAxes() {
    glColor3f(1.0f, 1.0f, 1.0f);
    drawLine(-10.0f, 0.0f, 10.0f, 0.0f); // X-axis
    drawLine(0.0f, -10.0f, 0.0f, 10.0f); // Y-axis
}

void drawObject() {
    glColor3f(1.0f, 1.0f, 1.0f);

    // Initial positions of points A and B
    float Ax = 0.0f, Ay = 7.0f;
    float Bx = 0.0f, By = 3.0f;

    // Apply transformations
    if (mirror) {
        Ax = -Ax;
        Bx = -Bx;
    }

    Ax = scale_factor * (Ax * cos(angle) - Ay * sin(angle)) + translation_x;
    Ay = scale_factor * (Ax * sin(angle) + Ay * cos(angle)) + translation_y;

    Bx = scale_factor * (Bx * cos(angle) - By * sin(angle)) + translation_x;
    By = scale_factor * (Bx * sin(angle) + By * cos(angle)) + translation_y;

    // Draw the transformed object
    drawPoint(Ax, Ay);
    drawPoint(Bx, By);
    drawLine(Ax, Ay, Bx, By);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawAxes();
    drawObject();

    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'r':
        angle += 0.1f;
        break;
    case 's':
        scale_factor += 0.1f;
        break;
    case 't':
        translation_x += 0.5f;
        break;
    case 'm':
        mirror = !mirror;
        break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("2D Transformation");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}
