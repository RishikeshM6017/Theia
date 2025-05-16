#include "PCH.h"

#include "VkUtility.h"


VkResult Vk::CreateInstance(VkInstance* pInstance)
{
	U32 apiVersion = 0;
	VK_CHECK(vkEnumerateInstanceVersion(&apiVersion));
	apiVersion &= ~(0xFFFU);

	VkApplicationInfo appInfo = {};
	appInfo.sType				= VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pNext				= nullptr;
	appInfo.pApplicationName	= "Theia";
	appInfo.applicationVersion	= VK_MAKE_API_VERSION(0, 1, 0, 0);
	appInfo.pEngineName			= "Theia Engine";
	appInfo.engineVersion		= VK_MAKE_API_VERSION(0, 1, 0, 0);
	appInfo.apiVersion			= VK_API_VERSION_1_3;


	U32 layerCount = 1;
	const char* layers[] = { "VK_LAYER_KHRONOS_validation" };

	U32 extensionCount = 3;
	const char* extensions[] = { "VK_EXT_debug_utils", "VK_KHR_surface", "VK_KHR_win32_surface" };

	VkDebugUtilsMessengerCreateInfoEXT debugMessengerInfo;
	Vk::PopulateDebugMessengerCreateInfo(debugMessengerInfo);

	VkInstanceCreateInfo instanceInfo = {};
	instanceInfo.sType						= VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instanceInfo.pNext						= &debugMessengerInfo;
	//instanceInfo.flags						= 0;
	instanceInfo.pApplicationInfo			= &appInfo;
	instanceInfo.enabledLayerCount			= layerCount;
	instanceInfo.ppEnabledLayerNames		= layers;
	instanceInfo.enabledExtensionCount		= extensionCount;
	instanceInfo.ppEnabledExtensionNames	= extensions;

	//TODO: Logger
	printf("Created Instance\n");

	return vkCreateInstance(&instanceInfo, nullptr, pInstance);
}

VkResult Vk::PickPhysicalDevice(VkInstance instance, VkPhysicalDevice* pPhysicalDevice)
{
	U32 physicalDeviceCount = 0;
	vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, nullptr);
	
	//TODO: Logger
	printf("Picked Physical Device: %s\n", "help");

	return VK_SUCCESS;
}

VkResult Vk::CreateLogicalDevice(VkInstance Instance, VkDevice* device)
{
	//TODO: Logger
	printf("Created Logical Device\n");

	return VK_SUCCESS;
}



VkResult Vk::SetupDebugMessenger(VkInstance instance, VkDebugUtilsMessengerEXT* pDebugMessenger)
{
	VkDebugUtilsMessengerCreateInfoEXT debugMessengerInfo = {};
	Vk::PopulateDebugMessengerCreateInfo(debugMessengerInfo);

	Vk::CreateDebugUtilsMessengerEXT(instance, &debugMessengerInfo, nullptr, pDebugMessenger);

	//TODO: Logger
	printf("Created Debug Messenger\n");

	return VK_SUCCESS;
}

VkResult Vk::CheckValidationLayerSupport(VkInstance* pInstance)
{
	return VK_SUCCESS;
}

void	 Vk::PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& pDebugMessengerInfo)
{
	pDebugMessengerInfo = {};
	pDebugMessengerInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
	//debugMessengerInfo.pNext			= nullptr;
	//debugMessengerInfo.flags			= 0;
	pDebugMessengerInfo.messageSeverity =
		VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
		VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
		VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
	pDebugMessengerInfo.messageType =
		VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
		VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
		VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
	pDebugMessengerInfo.pfnUserCallback = Vk::DebugCallback;
	pDebugMessengerInfo.pUserData = nullptr;
}

VkResult Vk::CreateDebugUtilsMessengerEXT
(
	VkInstance instance, 
	const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkDebugUtilsMessengerEXT* pDebugMessenger
)
{
	auto func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
	if (func != nullptr) {
		return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
	}
	else {
		return VK_ERROR_EXTENSION_NOT_PRESENT;
	}
}

void	Vk::DestroyDebugUtilsMessengerEXT
(
	VkInstance						instance,
	VkDebugUtilsMessengerEXT		debugMessenger,
	const VkAllocationCallbacks* pAllocator
)
{
	auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
	if (func != nullptr) {
		func(instance, debugMessenger, pAllocator);
	}
}


VKAPI_ATTR VkBool32 VKAPI_CALL Vk::DebugCallback
(
	VkDebugUtilsMessageSeverityFlagBitsEXT msgSeverity,
	VkDebugUtilsMessageTypeFlagsEXT msgType,
	const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
	void* pUserData)
{
	printf("VULKAN: %s\n", pCallbackData->pMessage);

	return VK_FALSE;
}
