#include "PCH.h"

#include "Renderer.h"

Renderer::Renderer(int width, int height) : width(width), height(height)
{
}

void Renderer::Initialize()
{
	Platform::Initialize();
	window = Platform::BuildWindow(width, height);

	Vk::CreateInstance(&instance);
	Vk::SetupDebugMessenger(instance, &debugMessenger);
	Vk::PickPhysicalDevice(instance, &physicalDevice);
	Vk::CreateLogicalDevice(instance, &device);
}

void Renderer::Run()
{
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}
}

void Renderer::Shutdown()
{
	Vk::DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);

	vkDestroyDevice(device, nullptr);
	vkDestroyInstance(instance, nullptr);

	Platform::Shutdown(window);
}
