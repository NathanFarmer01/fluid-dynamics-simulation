// Application initialization parameters

#pragma once

namespace Config
{
	//GLFW Params
	const unsigned int windowWidth = 1920;
	const unsigned int windowHeight = 1080;

	//Vulkan Params
	const std::vector<const char*> validationLayers = {
	"VK_LAYER_KHRONOS_validation"
	};
	const std::vector<const char*> deviceExtensions = {
	VK_KHR_SWAPCHAIN_EXTENSION_NAME
	};
	const int MAX_FRAMES_IN_FLIGHT = 2;
}