/// @file

#include <GLFW/glfw3.h>

#include "RenderWindowGLFW.hpp"
#include "InputEventDispatcher.hpp"

int GLFWKeyToInternalKey(int anKey)
{
	// TODO
	return 0;
};

/*
int InternalKeyToGLFWKey(int anKey)
{
};
*/

CInputEventDispatcher *gpInputEventDispatcher{nullptr};

CRenderWindowGLFW::CRenderWindowGLFW(CInputEventDispatcher *apInputEventDispatcher)
{
	gpInputEventDispatcher = apInputEventDispatcher;
};

CRenderWindowGLFW::~CRenderWindowGLFW() = default;

/*
static void error_callback(int error, const char *description)
{
    fprintf(stderr, "Error: %s\n", description);
};

static void close_callback(GLFWwindow *window)
{
};
*/

static void key_callback(GLFWwindow *apWindow, int anKey, int anScanCode, int anAction, int anModifiers)
{
    if(anKey == GLFW_KEY_ESCAPE && anAction == GLFW_PRESS)
	{
        glfwSetWindowShouldClose(apWindow, GLFW_TRUE);
		return;
	};
	
	switch(anAction)
	{
	case GLFW_PRESS:
		gpInputEventDispatcher->KeyPressed(anKey);
		break;
	case GLFW_RELEASE:
		gpInputEventDispatcher->KeyReleased(anKey);
		break;
	};
};

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
	
	glfwSetKeyCallback(mpWindow, key_callback);
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