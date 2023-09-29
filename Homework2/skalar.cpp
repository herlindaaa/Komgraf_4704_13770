#include <iostream>
#include <GLFW/glfw3.h>

float A[2][2] = {{1.0f, 2.0f}, {3.0f, 4.0f}};
float n = 2.0f;

float result[2][2];

void multiplyMatrixByScalar(float matrix[2][2], float scalar, float result[2][2]) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Gagal menginisialisasi GLFW" << std::endl;
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(640, 480, "Operasi Matriks", NULL, NULL);
    if(!window) {
        std::cerr << "Gagal membuat jendela GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    multiplyMatrixByScalar(A, n, result);
    std::cout << "Hasil Matrik A x n:" << std::endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}