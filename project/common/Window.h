#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <stdio.h>

#include "common.h"

GLFWwindow *InitWindow(int width, int height, const char *title);
void ClearBackground(Color color);
void UpdateWindow(GLFWwindow *window);

#endif // __WINDOW_H__
