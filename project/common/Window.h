#ifndef __GRAPHIC_H__
#define __GRAPHIC_H__

#include <stdio.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "common.h"

GLFWwindow *InitWindow(int width, int height, const char *title);
void ClearBackground(Color color);
void UpdateWindow(GLFWwindow *window);

#endif // __GRAPHIC_H__
