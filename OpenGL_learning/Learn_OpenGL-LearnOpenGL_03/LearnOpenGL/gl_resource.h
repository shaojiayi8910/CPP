#pragma once
#include <iostream>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "camera.h"

class GLResource//这个类中主要是实现GL资源与相机的设置
{
public:
	GLResource();
	~GLResource();
	bool CreateGLFWWindow(unsigned int uiWidth, unsigned int uiHeight, const std::string& sWindowName);
	GLFWwindow* GetGLFWWindow() const;
	void ResizeWindow(unsigned int uiWidth, unsigned int uiHeight);
	std::string GetGPUVersion() const;
	void SetCamera(std::shared_ptr<Camera>& spCamera);

private:
	GLFWwindow* m_pGLFWwindow;
};