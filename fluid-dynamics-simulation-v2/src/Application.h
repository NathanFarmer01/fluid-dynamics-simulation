#pragma once

#include <optional>
#include <vector>
#include <iostream>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

struct QueueFamilyIndices
{
	std::optional<uint32_t> graphicsFamily;
	std::optional<uint32_t> presentFamily;

	bool IsComplete()
	{
		return graphicsFamily.has_value() && presentFamily.has_value();
	}
};
struct SwapChainSupportDetails
{
	VkSurfaceCapabilitiesKHR capabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> presentModes;
};


class Application
{
public:
	Application();
	~Application();

	void Run();
private:
	//GLFW and Vulkan variables/initialization
	GLFWwindow* window;
	void InitWindow();
	VkInstance vulkanInstance;
	void InitVulkan();
	void CreateVulkanInstance();
	bool CheckValidationLayerSupport();
	VkSurfaceKHR surface;
	void CreateSurface();
	VkPhysicalDevice physicalDevice;
	void PickPhysicalDevice();
	bool IsDeviceSuitable(VkPhysicalDevice device);
	QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
	bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
	SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device);
	VkDevice device;
	VkQueue graphicsQueue;
	VkQueue presentQueue;
	void CreateLogicalDevice();
	VkSwapchainKHR swapChain;
	std::vector<VkImage> swapChainImages;
	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent;
	void CreateSwapChain();
	VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
	VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	void RecreateSwapChain();
	void CleanupSwapChain();
	std::vector<VkImageView> swapChainImageViews;
	void CreateImageViews();
	VkRenderPass renderPass;
	void CreateRenderPass();
	VkPipelineLayout pipelineLayout;
	VkPipeline graphicsPipeline;
	void CreateGraphicsPipeline();
	VkShaderModule createShaderModule(const std::vector<char>& code);
	std::vector<VkFramebuffer> swapChainFramebuffers;
	void CreateFramebuffers();
	VkCommandPool commandPool;
	void CreateCommandPool();
	std::vector<VkCommandBuffer> commandBuffers;
	void CreateCommandBuffers();
	void RecordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
	std::vector<VkSemaphore> imageAvailableSemaphores;
	std::vector<VkSemaphore> renderFinishedSemaphores;
	std::vector<VkFence> inFlightFences;
	void CreateSyncObjects();
	uint32_t currentFrame = 0;
	bool framebufferResized = false;
	void DrawFrame();
	static void GLFWErrorCallback(int error, const char* description);
	static void GLFWFramebufferResizeCallback(GLFWwindow* window, int width, int height);
	static void VkCheckResult(VkResult err);
	static std::vector<char> readFile(const std::string& filename);
};