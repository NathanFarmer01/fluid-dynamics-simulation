// Fluid Dynamics Simulation application entry point
// Modify Config.h to change the application's initialization parameters

#include <iostream>
#include <stdexcept>
#include "Application.h"

int main()
{
	try {
		Application app;
		app.Run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		std::cin.get();
	}
}