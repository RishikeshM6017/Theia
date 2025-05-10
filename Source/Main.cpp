#include <stdio.h>
#include <assert.h>

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>


typedef uint32_t U32;

#define U32(x) static_cast<U32>(x)

#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[1])

#define VK_CHECK(x) assert(x == VK_SUCCESS)


const int width = 960, height = 540;

namespace Vk
{

	VkResult CreateInstance(VkInstance* pInstance)
	{
		U32 apiVersion = 0;
		VK_CHECK(vkEnumerateInstanceVersion(&apiVersion));
		apiVersion &= ~(0xFFFU);

		VkApplicationInfo appInfo = {};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pNext = nullptr;
		appInfo.pApplicationName = "Theia";
		appInfo.applicationVersion = VK_MAKE_API_VERSION(0, 1, 0, 0);
		appInfo.pEngineName = "Theia Engine";
		appInfo.engineVersion = VK_MAKE_API_VERSION(0, 1, 0, 0);
		appInfo.apiVersion = apiVersion;

		U32 layerCount = 1;
		const char* layers[] = { "VK_LAYER_KHRONOS_validation" };

		U32 extensionCount = 0;
		const char** extensions = glfwGetRequiredInstanceExtensions(&extensionCount);


		VkInstanceCreateInfo instanceInfo = {};
		instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		//instanceInfo.pNext						= nullptr;
		//instanceInfo.flags						= 0;
		instanceInfo.pApplicationInfo = &appInfo;
		instanceInfo.enabledLayerCount = layerCount;
		instanceInfo.ppEnabledLayerNames = layers;
		instanceInfo.enabledExtensionCount = extensionCount;
		instanceInfo.ppEnabledExtensionNames = extensions;

		return vkCreateInstance(&instanceInfo, nullptr, pInstance);
	}
}

int main()
{
	VkInstance instance;
	VkPhysicalDevice physicalDevice;

	assert(glfwInit() == GL_TRUE);

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE,  GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(width, height, "Theia", NULL, NULL);
	assert(window != NULL);


	VK_CHECK(Vk::CreateInstance(&instance));

	U32 physicalDeviceCount = 0;
	VkPhysicalDevice physicalDevices[16];
	VK_CHECK(vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, nullptr));
	VK_CHECK(vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, physicalDevices));

	for (const auto& device : physicalDevices)
	{
		//TODO: More robust selection of GPU
		physicalDevice = device;
		break;
	}


	//VK_CHECK(

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	
	vkDestroyInstance(instance, nullptr);

	glfwDestroyWindow(window);

	glfwTerminate();

	return 0;
}