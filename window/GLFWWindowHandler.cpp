#include "GLFWWindowHandler.h"

Erbium::GLFWWindowHandler::GLFWWindowHandler()
{
	this->type = MODULE_WINDOW;
}

Erbium::GLFWWindowHandler::~GLFWWindowHandler()
{
}

void Erbium::GLFWWindowHandler::init()
{
	initWindow();
}

void Erbium::GLFWWindowHandler::update(uint32_t deltaTime)
{
	if (!this->shouldClose()) {
		this->poolEvents();
		this->swapBuffers();
	}
}

void Erbium::GLFWWindowHandler::disable()
{
}

void Erbium::GLFWWindowHandler::terminate()
{
	glfwDestroyWindow(this->windowPtr);
	glfwTerminate();
}

void Erbium::GLFWWindowHandler::onEvent(Event* event)
{
}

void Erbium::GLFWWindowHandler::initWindow()
{

	if (!glfwInit()) {
		Logger::Log(LOG_CRITICAL, "GLFW init error!");
		return;
	}

	this->windowPtr = glfwCreateWindow(this->windowWidth, this->windowHeight, this->title, NULL, NULL);
	if (!this->windowPtr) {
		Logger::Log(LOG_CRITICAL, "glfwCreateWindow error!");
		this->terminate();
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwMakeContextCurrent(this->windowPtr);
}

bool Erbium::GLFWWindowHandler::shouldClose()
{
	return glfwWindowShouldClose(this->windowPtr);
}

void Erbium::GLFWWindowHandler::poolEvents()
{
	glfwPollEvents();
}

void Erbium::GLFWWindowHandler::swapBuffers()
{
	glfwSwapBuffers(this->windowPtr);
}
