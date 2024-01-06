#include <GL/glut.h>

float angleX = 0.0f;
float angleY = 0.0f;
float scale_factor = 1.0f;
float translation_x = 0.0f, translation_y = 0.0f, translation_z = 0.0f;

void drawCube()
{
    glutWireCube(1.0f);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glTranslatef(translation_x, translation_y, translation_z);
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    glScalef(scale_factor, scale_factor, scale_factor);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCube();
    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / height, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'x':
            angleX += 5.0f;
            break;
        case 'y':
            angleY += 5.0f;
            break;
        case 's':
            scale_factor += 0.1f;
            break;
        case 't':
            translation_x += 0.1f;
            break;
        case 'q':
            translation_y += 0.1f;
            break;
        case 'w':
            translation_z += 0.1f;
            break;
        case 27: // ASCII code for 'Esc' key
            exit(0);
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Transformation");
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
