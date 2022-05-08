#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cmath>
#include <array>
#include "Rectangle.h"
#include "Screen.h"

#define TITLE_PREFIX "Proyecto 1 Fundamentos de la Computació G"



int main(int argc, char* argv[])
{
    //std::array<float,4> pos = { 1.0f, 1.0f, 1.0f, 1.0f};  
    //std::array<float,4> col = { 1.0f, 1.0f, 1.0f, 1.0f};
 
    //Rectangle rect =  Rectangle(pos, col);
    Screen pantalla = Screen();
    pantalla.InitializeScreen();

    return 0;
}
