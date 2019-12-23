#pragma once

#include "3rdParty/GLFW/glfw3.h"
#include "../utils/Logger.h"
#include "../Erbium/Module.h"


namespace Erbium {


	class GLFWWindowHandler : public Module
	{
	
		GLFWwindow* windowPtr;

		int windowWidth = 640;
		int windowHeight = 480;
		const char* title = "Default Title";
	public:
		GLFWWindowHandler();
		~GLFWWindowHandler() override;

		void init() override;
		void update(uint32_t deltaTime) override;
		void disable() override;
		void terminate() override;

		void onEvent(Event* event) override;


		void initWindow();
		bool shouldClose();
		void poolEvents();
		void swapBuffers();
	};

}