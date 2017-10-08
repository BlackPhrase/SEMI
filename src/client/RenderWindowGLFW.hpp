#pragma once

typedef struct GLFWwindow GLFWwindow;

class CRenderWindowGLFW final
{
public:
	CRenderWindowGLFW();
	~CRenderWindowGLFW();
	
	bool Init(int width, int height, const char *title);
	void Shutdown();
	
	void Update();
	
	void SetSize(int width, int height);
	//GetSize() const;
	
	void SetPos(int x, int y);
	//GetPos() const;
	
	void SetTitle(const char *title);
	const char *GetTitle() const;
	
	bool WantClose() const;
private:
	GLFWwindow *mpWindow{nullptr};
};