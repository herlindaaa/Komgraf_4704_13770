#include <iostream>
#include <GLFW/glfw3.h>

float A[2][2] = {{1.0f, 2.0f}, {3.0f, 4.0f}};
float B[2][2] = {{1.0f, 1.0f}, {1.0f, 2.0f}};
float C[2][2];

void multiplyMatrix(float matA[2][2], float matB[2][2], float result[2][2]) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < 2; k++) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

int main() {
    if(!glfwInit()) {
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
    multiplyMatrix(A, B, C);
    std::cout << "Hasil Matriks A x B:" << std::endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            std::cout << C[i][j] << " ";
        }
        std::cout << std::endl;
    }
    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}