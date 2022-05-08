#ifndef SCREEN_H_
#define SCREEN_H_
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>


class Screen
{
    
    public:

        const int SCR_WIDTH = 800;
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
        GLFWwindow* window;
        Screen();
        void InitializeScreen();
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
        static void glfw_onKey(GLFWwindow* window, int key, int scancode, int action, int mode);
        //static void colorTriangle();
        static void eventosTeclado(GLFWwindow* window, int key, int scancode, int action, int mode);
        //void InitializeGl();
        //void InitializeWindows();

        virtual ~Screen();

        

};
#endif 
