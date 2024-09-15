#ifndef __COMMON_H__
#define __COMMON_H__

#include "../vendor/glad/glad.h"
#include "../vendor/GLFW/glfw3.h"
#include "../vendor/stb/stb_image.h"

#include <stdio.h>
#include <stdbool.h>

typedef struct Color {
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
} Color;

#endif // __COMMON_H__
