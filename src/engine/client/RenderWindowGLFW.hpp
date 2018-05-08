/// @file

#pragma once

#include "IRenderWindow.hpp"

typedef struct GLFWwindow GLFWwindow;

class CInputEventDispatcher;

class CRenderWindowGLFW final : public IRenderWindow
{
public:
	CRenderWindowGLFW(CInputEventDispatcher *apInputEventDispatcher);
	~CRenderWindowGLFW();
	
	bool Init(int width, int height, const char *title) override;
	void Shutdown() override;
	
	void Update() override;
	
	void SetSize(int width, int height) override;
	//GetSize() const;
	
	void SetPos(int x, int y) override;
	//GetPos() const;
	
	void SetTitle(const char *title) override;
	const char *GetTitle() const override;
	
	bool WantClose() const override;
private:
	GLFWwindow *mpWindow{nullptr};
};