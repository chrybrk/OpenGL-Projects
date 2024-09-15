#ifndef __MATH_H__
#define __MATH_H__

#include <stdlib.h>
#include <math.h>

//----------------------------------------------------------------------------------
// Defines and Macros
//----------------------------------------------------------------------------------
#ifndef PI
    #define PI 3.14159265358979323846f
#endif

#ifndef EPSILON
    #define EPSILON 0.000001f
#endif

#ifndef DEG2RAD
    #define DEG2RAD (PI/180.0f)
#endif

#ifndef RAD2DEG
    #define RAD2DEG (180.0f/PI)
#endif

typedef struct Vec2 {
	float x;
	float y;
} Vec2;

typedef struct Vec3 {
	float x;
	float y;
	float z;
} Vec3;

typedef struct Vec4 {
	float x;
	float y;
	float z;
	float w;
} Vec4;

typedef Vec4 Quaternion;

// OpenGL style 4x4 right handed, clm major
typedef struct Mat4x4 {
	float m0, m4, m8,  m12;
	float m1, m5, m9,  m13;
	float m2, m6, m10, m14;
	float m3, m7, m11, m15;
} Mat4x4;

typedef struct float3 {
	float v[3];
} float3;

typedef struct float16 {
	float v[16];
} float16;

// Clamp float value
float Clamp(float value, float min, float max);

// Calculate linear interpolation between two floats
float Lerp(float start, float end, float amount);

// Normalize input value within input range
float Normalize(float value, float start, float end);

// Remap input value within input range to output range
float Remap(float value, float inputStart, float inputEnd, float outputStart, float outputEnd);

// Wrap input value from min to max
float Wrap(float value, float min, float max);

// Check whether two given floats are almost equal
int FloatEquals(float x, float y);

float easeIn(float x);

float easeInOutCubic(float x);

float easeInElastic(float x);

float easeOutBounce(float x);

float easeMine(float x);


/*
	/////////////////////////////////////////////////////////
	///
	///	Vector 2 Related functions
	///
	/////////////////////////////////////////////////////////
*/

// returns Vec2 with components being 0.0f
Vec2 Vec2Zero(void);

// returns Vec2 with components being 1.0f
Vec2 Vec2One(void);

// returns addition of two vector
Vec2 Vec2Add(const Vec2 v1, const Vec2 v2);

// returns addition in Vector with imm value
Vec2 Vec2AddV(const Vec2 v, float f);

// returns subtraction of two vector
Vec2 Vec2Sub(const Vec2 v1, const Vec2 v2);

// returns subtraction in Vector with imm value
Vec2 Vec2SubV(const Vec2 v, float f);

// multiply by scale
Vec2 Vec2Scale(const Vec2 v, float f);

// multiply two vectors
Vec2 Vec2Multiply(const Vec2 v1, const Vec2 v2);

// divide two vectors
Vec2 Vec2Divide(const Vec2 v1, const Vec2 v2);

// calculate vector length
float Vec2Length(const Vec2 v);

// dot prod of vector
float Vec2DotProduct(const Vec2 v1, const Vec2 v2);

// distance between two vectors
float Vec2Distance(const Vec2 v1, const Vec2 v2);

// angle between two vectors from origin (0, 0)
float Vec2Angle(const Vec2 v1, const Vec2 v2);

// angle from *A to *B
float Vec2LineAngle(const Vec2 start, const Vec2 end);

// return normalized vector
Vec2 Vec2Normalize(const Vec2 v);

// transform a vector by given matrix
Vec2 Vec2Transform(Vec2 v, Mat4x4 m);

// linear interpolation between two vectors by amount
Vec2 Vec2Lerp(const Vec2 v1, const Vec2 v2, float amount);

// calculate reflected vector to normal
Vec2 Vec2Reflect(const Vec2 v, const Vec2 normal);

// rotate vector by angle
Vec2 Vec2Rotate(const Vec2 v, float angle);

/*
	/////////////////////////////////////////////////////////
	///
	///	Vector 3 Related functions
	///
	/////////////////////////////////////////////////////////
*/

// returns Vec3 with components being 0.0f
Vec3 Vec3Zero(void);

// returns Vec3 with components being 1.0f
Vec3 Vec3One(void);

// returns addition of two vector
Vec3 Vec3Add(const Vec3 v1, const Vec3 v2);

// returns addition in Vector with imm value
Vec3 Vec3AddV(const Vec3 v, float f);

// returns subtraction of two vector
Vec3 Vec3Sub(const Vec3 v1, const Vec3 v2);

// returns subtraction in Vector with imm value
Vec3 Vec3SubV(const Vec3 v, float f);

// multiply by scale
Vec3 Vec3Scale(const Vec3 v, float f);

// multiply two vectors
Vec3 Vec3Multiply(const Vec3 v1, const Vec3 v2);

// divide two vectors
Vec3 Vec3Divide(const Vec3 v1, const Vec3 v2);

// calculate vector length
float Vec3Length(const Vec3 v);

// calculate perpendicular vector
Vec3 Vec3Perpendicular(const Vec3 v);

// cross prod of vector
Vec3 Vec3CrossProduct(const Vec3 v1, const Vec3 v2);

// dot prod between two vectors
float Vec3DotProduct(const Vec3 v1, const Vec3 v2);

// distance between two vectors
float Vec3Distance(const Vec3 v1, const Vec3 v2);

// angle between two vectors from origin (0, 0)
float Vec3Angle(const Vec3 v1, const Vec3 v2);

// return normalized vector
Vec3 Vec3Normalize(const Vec3 v);

// transform a vector by given matrix
Vec3 Vec3Transform(Vec3 v, Mat4x4 m);

// linear interpolation between two vectors by amount
Vec3 Vec3Lerp(const Vec3 v1, const Vec3 v2, float amount);

// calculate reflected vector to normal
Vec3 Vec3Reflect(const Vec3 v, const Vec3 normal);

// calculate projection of the v1 on to v2
Vec3 Vec3Project(const Vec3 v1, const Vec3 v2);

// calculate rejection of the v1 on to v2
Vec3 Vec3Reject(const Vec3 v1, const Vec3 v2);

// rotate by quaternion
Vec3 Vec3RotateByQuaternion(const Vec3 v, const Quaternion q);

// rotates a vector around an axis
Vec3 Vec3RotateByAxisAngle(Vec3 v, Vec3 axis, float angle);

/*
	/////////////////////////////////////////////////////////
	///
	///	Vector 4 Related functions
	///
	/////////////////////////////////////////////////////////
*/

// returns Vec4 with components being 0.0f
Vec4 Vec4Zero(void);

// returns Vec4 with components being 1.0f
Vec4 Vec4One(void);

// returns addition of two vector
Vec4 Vec4Add(const Vec4 v1, const Vec4 v2);

// returns addition in Vector with imm value
Vec4 Vec4AddV(const Vec4 v, float f);

// returns subtraction of two vector
Vec4 Vec4Sub(const Vec4 v1, const Vec4 v2);

// returns subtraction in Vector with imm value
Vec4 Vec4SubV(const Vec4 v, float f);

// multiply by scale
Vec4 Vec4Scale(const Vec4 v, float f);

// multiply two vectors
Vec4 Vec4Multiply(const Vec4 v1, const Vec4 v2);

// divide two vectors
Vec4 Vec4Divide(const Vec4 v1, const Vec4 v2);

// calculate vector length
float Vec4Length(const Vec4 v);

// calculate dot prod of two vectors
float Vec4DotProduct(const Vec4 v1, const Vec4 v2);

// distance between two vectors
float Vec4Distance(const Vec4 v1, const Vec4 v2);

// return normalized vector
Vec4 Vec4Normalize(const Vec4 v);

// linear interpolation between two vectors by amount
Vec4 Vec4Lerp(const Vec4 v1, const Vec4 v2, float amount);

/*
	/////////////////////////////////////////////////////////
	///
	///	Matrix Related functions
	///
	/////////////////////////////////////////////////////////
*/

// multiply A*B matrix
float *MatrixMultiply(float *A, float *B, size_t Ar, size_t Ac, size_t Br, size_t Bc);

// compute matrix determinant
float Mat4x4Determinant(Mat4x4 m);

// get the sum of values along diagonal
float Mat4x4SumAlongDiag(Mat4x4 m);

// transpose of a matrix
Mat4x4 Mat4x4Transpose(Mat4x4 m);

// invert of a matrix
Mat4x4 Mat4x4Invert(Mat4x4 m);

// identity matrix 
Mat4x4 Mat4x4Identity(void);

// addition of two matrix
Mat4x4 Mat4x4Add(Mat4x4 m1, Mat4x4 m2);

// subtraction of two matrix 
Mat4x4 Mat4x4Subtract(Mat4x4 m1, Mat4x4 m2);

// multiplication of two matrix 
Mat4x4 Mat4x4Multiply(Mat4x4 m1, Mat4x4 m2);

// get translation matrix
Mat4x4 Mat4x4Translation(const Vec3 v);

// rotation matrix from axis and angle
Mat4x4 Mat4x4Rotate(const Vec3 axis, float angle);

// get prespective projection matrix
Mat4x4 Mat4x4Frustum(double left, double right, double bottom, double top, double near, double far);

// get prespective projection matrix
Mat4x4 Mat4x4Prespective(double fov, double aspect, double near, double far);

// get orthographic projection matrix
Mat4x4 Mat4x4Ortho(double left, double right, double bottom, double top, double near, double far);

// view matrix
Mat4x4 Mat4x4LookAt(const Vec3 from, const Vec3 to, const Vec3 up);

// matrix to float array
float16 Mat4x4ToFloat(const Mat4x4 m);

/*
	/////////////////////////////////////////////////////////
	///
	///	Quaternion Related functions
	///
	/////////////////////////////////////////////////////////
*/

// add two quaternion
Quaternion QuaternionAdd(const Quaternion q1, const Quaternion q2);

// add quaternion and value
Quaternion QuaternionAddValue(const Quaternion q, float f);

// sub two quaternion
Quaternion QuaternionSubtract(const Quaternion q1, const Quaternion q2);

// sub quaternion and value
Quaternion QuaternionSubtractValue(const Quaternion q, float f);

// quaternion identity
Quaternion QuaternionIdentity(void);

// length of quaternion
float QuaternionLength(const Quaternion q);

// normalize quaternion
Quaternion QuaternionNormalize(const Quaternion q);

// invert quaternion
Quaternion QuaternionInvert(const Quaternion q);

// multiply of two quaternion
Quaternion QuaternionMultiply(const Quaternion q1, const Quaternion q2);

// scale quaternion by a value
Quaternion QuaternionScale(const Quaternion q, float f);

// divide of two quaternion
Quaternion QuaternionDivide(const Quaternion q1, const Quaternion q2);

// lerp between two quaternion
Quaternion QuaternionLerp(const Quaternion q1, const Quaternion q2, float amount);

// calculate slerp-optimized interpolation between two quaternion
Quaternion QuaternionNlerp(const Quaternion q1, const Quaternion q2, float amount);

// calculate spherical linear interpolation between two quaternion
Quaternion QuaternionSlerp(const Quaternion q1, const Quaternion q2, float amount);

// quaternion from matrix
Quaternion QuaternionFromMatrix(const Mat4x4 m);

// get a matrix for a given quaternion
Mat4x4 QuaternionToMatrix(const Quaternion q);

// get rotation for an angle and axis
Quaternion QuaternionFromAxisAngle(Vec3 axis, float angle);

// get the rotation angle and axis for a given quaternion
void QuaternionToAxisAngle(Quaternion q, Vec3 *outAxis, float *outAngle);

// Get the quaternion equivalent to Euler angles
// NOTE: Rotation order is ZYX
Quaternion QuaternionFromEuler(float pitch, float yaw, float roll);

// Get the Euler angles equivalent to quaternion (roll, pitch, yaw)
// NOTE: Angles are returned in a Vector3 struct in radians
Vec3 QuaternionToEuler(Quaternion q);

// Transform a quaternion given a transformation matrix
Quaternion QuaternionTransform(Quaternion q, Mat4x4 mat);

#endif // __MATH_H__
