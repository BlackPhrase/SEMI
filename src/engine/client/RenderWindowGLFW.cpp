/// @file

#include <GLFW/glfw3.h>

#include "RenderWindowGLFW.hpp"

CRenderWindowGLFW::CRenderWindowGLFW() = default;
CRenderWindowGLFW::~CRenderWindowGLFW() = default;

/*
static void error_callback(int error, const char *description)
{
    fprintf(stderr, "Error: %s\n", description);
};

static void close_callback(GLFWwindow *window)
{
};

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
*/

bool CRenderWindowGLFW::Init(int width, int height, const char *title)
{
	if(!glfwInit())
		return false;
	
	//glfwSetErrorCallback(error_callback);
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	
	mpWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
	
	if(!mpWindow)
	{
		glfwTerminate();
		return false;
	};
	
	//glfwSetWindowCloseCallback(mpWindow, close_callback);
	
	glfwMakeContextCurrent(mpWindow);
	glfwSwapInterval(1);
	
	//glfwSetKeyCallback(mpWindow, key_callback);
	return true;
};

void CRenderWindowGLFW::Shutdown() // TODO: move to destructor
{
	glfwDestroyWindow(mpWindow);
	
	glfwTerminate();
};

void CRenderWindowGLFW::Update()
{
	//glfwGetFramebufferSize(mpWindow, &width, &height);
	
	//glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glfwSwapBuffers(mpWindow);
	
	glfwPollEvents();
};

void CRenderWindowGLFW::SetSize(int width, int height)
{
	glfwSetWindowSize(mpWindow, width, height);
};

void CRenderWindowGLFW::SetPos(int x, int y)
{
	glfwSetWindowPos(mpWindow, x, y);
};

void CRenderWindowGLFW::SetTitle(const char *title)
{
	glfwSetWindowTitle(mpWindow, title);
};

const char *CRenderWindowGLFW::GetTitle() const
{
	//return glfwWindowGetTitle(mpWindow);
	return "";
};

bool CRenderWindowGLFW::WantClose() const
{
	return glfwWindowShouldClose(mpWindow);
};