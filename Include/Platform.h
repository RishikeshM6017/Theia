#pragma once

#include "PCH.h"

namespace Platform
{
	void Initialize();

	GLFWwindow* BuildWindow(int width, int height);

	void GetSurface(GLFWwindow* window);

	void Shutdown(GLFWwindow* window);

};

