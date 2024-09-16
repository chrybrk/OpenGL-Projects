#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "cmath.h"

typedef struct Camera {
    Vec3 position;
    Vec3 target;
    Vec3 up;
} Camera;

#endif // __CAMERA_H__