#pragma once

#include "PCH.h"

#include "Platform.h"
#include "VkUtility.h"

class Renderer
{
public:
	Renderer(int width, int height);
	~Renderer();

public:
	void Initialize();
	void Run();
	void Shutdown();

public:
	VkInstance			instance;
	VkPhysicalDevice	physicalDevice;
	VkDevice			device;

	VkDebugUtilsMessengerEXT debugMessenger;

	GLFWwindow* window;

	int width;
	int height;
};

