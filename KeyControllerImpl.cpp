#include "KeyController.h"

KeyController::KeyController()
{


}
KeyController::~KeyController(){

}
void KeyController::eventosTeclado(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
