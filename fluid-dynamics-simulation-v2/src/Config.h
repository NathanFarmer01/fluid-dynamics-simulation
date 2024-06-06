// Application initialization parameters

#pragma once

namespace Config
{
	const unsigned int windowWidth = 1920;
	const unsigned int windowHeight = 1080;

	const std::vector<const char*> validationLayers = {
	"VK_LAYER_KHRONOS_validation"
	};

	const std::vector<const char*> deviceExtensions = {
	VK_KHR_SWAPCHAIN_EXTENSION_NAME
	};
}