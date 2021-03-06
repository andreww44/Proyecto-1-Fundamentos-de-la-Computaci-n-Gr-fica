#ifndef SCREEN_H_
#define SCREEN_H_
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Rectangle.h"
#include "KeyController.h"
#include <iostream>
#include <cmath>


class Screen
{
        Rectangle figura;
        KeyController controllador;
    public:
        const int SCR_WIDTH = 600;
        const int SCR_HEIGHT = 600;
        const char *vertexShaderSource ="#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos, 1.0);\n"
            "}\0";
        const char *fragmentShaderSource = "#version 330 core\n"
            "out vec4 FragColor;\n"
            "uniform vec4 ourColor;\n"
            "void main()\n"
            "{\n"
            "   FragColor = ourColor;\n"
            "}\n\0";
        unsigned int shaderProgram;
        unsigned int VAO, VBO;
        GLFWwindow* window;
        Screen();
        void InitializeScreen();
        void FinishScreen();
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
        static void glfw_onKey(GLFWwindow* window, int key, int scancode, int action, int mode);
        static void eventosTeclado(GLFWwindow* window, int key, int scancode, int action, int mode);
        void Loop();
        virtual ~Screen();

        

};
#endif 
