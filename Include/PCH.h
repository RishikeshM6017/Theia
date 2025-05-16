#pragma once


#include <stdio.h>
#include <assert.h>

#include <vector>

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>


typedef uint32_t U32;


#define U32(x) static_cast<U32>(x)

#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[1])

#define VK_CHECK(x) assert(x == VK_SUCCESS)