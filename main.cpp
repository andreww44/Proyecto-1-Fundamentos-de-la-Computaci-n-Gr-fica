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
    Screen pantalla = Screen();
    pantalla.InitializeScreen();
    pantalla.Loop();
    pantalla.FinishScreen();
    return 0;
}
