#ifndef KEY_CONTROLLER_H_
#define KEY_CONTROLLER_H_
#include <array>
#include "Rectangle.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class KeyController
{    
    public:       
        KeyController();
        virtual ~KeyController();
        void eventosTeclado(GLFWwindow* window, int key, int scancode, int action, int mode);
        //void minusRed(); 
};
#endif 