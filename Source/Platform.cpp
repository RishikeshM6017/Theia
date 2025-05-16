#include "PCH.h"
#include "Platform.h"

void Platform::Initialize()
{
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE , GLFW_FALSE);
}

GLFWwindow* Platform::BuildWindow(int width, int height)
{
	return glfwCreateWindow(width, height, "Theia Renderer", NULL, NULL);
}

void Platform::GetSurface(GLFWwindow* window)
{
}

void Platform::Shutdown(GLFWwindow* window)
{
	glfwDestroyWindow(window);

	glfwTerminate();
}
