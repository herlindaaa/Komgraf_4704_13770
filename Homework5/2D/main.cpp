#include <GL/glut.h>

float angle = 0.0f;
float scale_factor = 1.0f;
float translation_x = 0.0f;
float translation_y = 0.0f;
bool mirror = false;

void drawObject() {
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
}

void applyTransformations() {
    glLoadIdentity();
    if (mirror) {
        glScalef(-1.0f, 1.0f, 1.0f);
    }
    glTranslatef(translation_x, translation_y, 0.0f);
    glScalef(scale_factor, scale_factor, 1.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    applyTransformations();
    drawObject();
    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'r':
        angle += 10.0f;
        break;
    case 's':
        scale_factor += 0.1f;
        break;
    case 't':
        translation_x += 0.1f;
        translation_y += 0.1f;
        break;
    case 'm':
        mirror = !mirror;
        break;
    case 27:
        exit(0);
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Transformasi 2D");
    glutInitWindowSize(500, 500);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();

    return 0;
}
