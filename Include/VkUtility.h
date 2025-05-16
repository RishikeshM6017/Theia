#pragma once

#include "PCH.h"

namespace Vk
{
	VkResult CreateInstance(VkInstance* pInstance);

	VkResult PickPhysicalDevice(VkInstance Instance, VkPhysicalDevice* pPhysicalDevice);

	VkResult CreateLogicalDevice(VkInstance Instance, VkDevice* device);
	


	//DEBUG FUNCTIONS
	VkResult CheckValidationLayerSupport(VkInstance* pInstance);

	void	 PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& pDebugMessengerInfo);

	VkResult SetupDebugMessenger(VkInstance instance, VkDebugUtilsMessengerEXT* pDebugMessenger);

	VkResult CreateDebugUtilsMessengerEXT
	(
		VkInstance									instance,
		const VkDebugUtilsMessengerCreateInfoEXT*	pCreateInfo,
		const VkAllocationCallbacks*				pAllocator,
		VkDebugUtilsMessengerEXT*					pDebugMessenger
	);

	void DestroyDebugUtilsMessengerEXT
	(
		VkInstance						instance,
		VkDebugUtilsMessengerEXT		debugMessenger,
		const VkAllocationCallbacks*	pAllocator
	);


	//CALLBACKS
	static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback
	(
		VkDebugUtilsMessageSeverityFlagBitsEXT		msgSeverity,
		VkDebugUtilsMessageTypeFlagsEXT				msgType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData
	);

};

