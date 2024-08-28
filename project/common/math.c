#include "math.h"

// Clamp float value
float Clamp(float value, float min, float max)
{
	float result = (value < min) ? min : value;

	if (result > max) result = max;

	return result;
}

// Calculate linear interpolation between two floats
float Lerp(float start, float end, float amount)
{
	float result = start + amount * (end - start);
	
	return result;
}

// Normalize input value within input range
float Normalize(float value, float start, float end)
{
	float result = (value - start) / (end - start);

	return result;
}

// Remap input value within input range to output range
float Remap(float value, float inputStart, float inputEnd, float outputStart, float outputEnd)
{
	float result = (value - inputStart) / (inputEnd - inputStart) * (outputEnd - outputStart) + outputStart;

	return result;
}

// Wrap input value from min to max
float Wrap(float value, float min, float max)
{
	float result = value - (max - min) * floorf((value - min) / (max - min));
	
	return result;
}

// Check whether two given floats are almost equal
int FloatEquals(float x, float y)
{
	int result = (fabs(x - y)) <= (EPSILON * fmaxf(1.0f, fmaxf(fabs(x), fabsf(y))));

	return result;
}


/*
	/////////////////////////////////////////////////////////
	///
	///	Vector 2 Related functions
	///
	/////////////////////////////////////////////////////////
*/

// returns Vec2 with components being 0.0f
Vec2 Vec2Zero(void)
{
	return (Vec2) { 0.0f, 0.0f };
}

// returns Vec2 with components being 1.0f
Vec2 Vec2One(void)
{
	return (Vec2) { 1.0f, 1.0f };
}

// returns addition of two vector
Vec2 Vec2Add(const Vec2 v1, const Vec2 v2)
{
	return (Vec2) { v1.x + v2.x, v2.y + v2.y };
}

// returns addition in Vector with imm value
Vec2 Vec2AddV(const Vec2 v, float f)
{
	return (Vec2) { v.x + f, v.y + f };
}

// returns subtraction of two vector
Vec2 Vec2Sub(const Vec2 v1, const Vec2 v2)
{
	return (Vec2) { v1.x - v2.x, v1.y - v2.y };
}

// returns subtraction in Vector with imm value
Vec2 Vec2SubV(const Vec2 v, float f)
{
	return (Vec2) { v.x - f, v.y - f };
}

// multiply by scale
Vec2 Vec2Scale(const Vec2 v, float f)
{
	return (Vec2) { v.x * f, v.y * f };
}

// multiply two vectors
Vec2 Vec2Multiply(const Vec2 v1, const Vec2 v2)
{
	return (Vec2) { v1.x * v2.x, v1.y * v2.y };
}

// divide two vectors
Vec2 Vec2Divide(const Vec2 v1, const Vec2 v2)
{
	return (Vec2) { v1.x / v2.x, v1.y / v2.y };
}

// calculate vector length
float Vec2Length(const Vec2 v)
{
	return sqrtf((v.x*v.x) + (v.y*v.y));
}

// dot prod of vector
float Vec2DotProduct(const Vec2 v1, const Vec2 v2)
{
	return (v1.x*v2.x + v1.y*v2.y);
}

// distance between two vectors
float Vec2Distance(const Vec2 v1, const Vec2 v2)
{
	return sqrtf((v1.x - v2.x)*(v1.x - v2.x) + (v1.y - v2.y)*(v1.y - v2.y));
}

// angle between two vectors from origin (0, 0)
float Vec2Angle(const Vec2 v1, const Vec2 v2)
{
	float result = 0.0f;

	float dot = v1.x*v2.x + v1.y*v2.y;
	float det = v1.x*v2.y - v1.y*v2.x;

	result = atan2f(det, dot);

	return result;
}

// angle from *A to *B
float Vec2LineAngle(const Vec2 start, const Vec2 end)
{
	float result = 0.0f;

	result = -atan2f(end.y - start.y, end.x - start.x);

	return result;
}

// return normalized vector
Vec2 Vec2Normalize(const Vec2 v)
{
	Vec2 result = { 0 };
	float length = sqrtf((v.x*v.x) + (v.y*v.y));

	if (length > 0)
	{
		float ilength = 1.0f/length;
		result.x = v.x*ilength;
		result.y = v.y*ilength;
	}

	return result;
}

// transform a vector by given matrix
Vec2 Vec2Transform(Vec2 v, Mat4x4 m)
{
	Vec2 result = { 0 };

	float x = v.x;
	float y = v.y;
	float z = 0;

	result.x = m.m0*x + m.m4*y + m.m8*z + m.m12;
	result.y = m.m1*x + m.m5*y + m.m9*z + m.m13;

	return result;
}

// linear interpolation between two vectors by amount
Vec2 Vec2Lerp(const Vec2 v1, const Vec2 v2, float amount)
{
	Vec2 result = { 0 };

	result.x = Lerp(v1.x, v2.x, amount);
	result.y = Lerp(v1.y, v2.y, amount);

	return result;
}

// calculate reflected vector to normal
Vec2 Vec2Reflect(const Vec2 v, const Vec2 normal)
{
	Vec2 result = { 0 };

	float dp = Vec2DotProduct(v, normal);

	result.x = v.x - (2.0f * normal.x) * dp;
	result.y = v.y - (2.0f * normal.y) * dp;

	return result;
}

// rotate vector by angle
Vec2 Vec2Rotate(const Vec2 v, float angle)
{
	Vec2 result = { 0 };

	float cosres = cosf(angle);
	float sinres = sinf(angle);

	result.x = v.x * cosres - v.y * sinres;
	result.y = v.x * sinres + v.y * cosres;

	return result;
}

/*
	/////////////////////////////////////////////////////////
	///
	///	Vector 3 Related functions
	///
	/////////////////////////////////////////////////////////
*/

// returns Vec3 with components being 0.0f
Vec3 Vec3Zero(void)
{
	return (Vec3) { 0.0f, 0.0f, 0.0f };
}

// returns Vec3 with components being 1.0f
Vec3 Vec3One(void)
{
	return (Vec3) { 1.0f, 1.0f, 1.0f };
}

// returns addition of two vector
Vec3 Vec3Add(const Vec3 v1, const Vec3 v2)
{
	return (Vec3) { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
}

// returns addition in Vector with float value 
Vec3 Vec3AddV(const Vec3 v, float f)
{
	return (Vec3) { v.x + f, v.y + f, v.z + f };
}

// returns subtraction of two vector
Vec3 Vec3Sub(const Vec3 v1, const Vec3 v2)
{
	return (Vec3) { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z };
}

// returns subtraction in Vector with imm value
Vec3 Vec3SubV(const Vec3 v, float f)
{
	return (Vec3) { v.x - f, v.y - f, v.z - f };
}

// multiply by scale
Vec3 Vec3Scale(const Vec3 v, float f)
{
	return (Vec3) { v.x * f, v.y * f, v.z * f };
}

// multiply two vectors
Vec3 Vec3Multiply(const Vec3 v1, const Vec3 v2)
{
	return (Vec3) { v1.x * v2.x, v1.y * v2.y, v1.z * v2.z };
}

// divide two vectors
Vec3 Vec3Divide(const Vec3 v1, const Vec3 v2)
{
	return (Vec3) { v1.x / v2.x, v1.y / v2.y, v1.z / v2.z };
}

// calculate vector length
float Vec3Length(const Vec3 v)
{
	return sqrtf((v.x*v.x) + (v.y*v.y) + (v.z*v.z));
}

// calculate perpendicular vector
Vec3 Vec3Perpendicular(const Vec3 v)
{
	float min = fabsf(v.x);
	Vec3 cardinalAxis = { 1.0f, 0.0f, 0.0f };

	if (fabsf(v.y) < min)
	{
		min = fabsf(v.y);
		Vec3 tmp = { 0.0f, 1.0f, 0.0f };
		cardinalAxis = tmp;
	}

	if (fabsf(v.z) < min)
	{
		min = fabsf(v.y);
		Vec3 tmp = { 0.0f, 0.0f, 1.0f };
		cardinalAxis = tmp;
	}

	return Vec3CrossProduct(v, cardinalAxis);
}

// cross prod of vector
Vec3 Vec3CrossProduct(const Vec3 v1, const Vec3 v2)
{
	return (Vec3) { v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x };
}

float Vec3DotProduct(const Vec3 v1, const Vec3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

// distance between two vectors
float Vec3Distance(const Vec3 v1, const Vec3 v2)
{
	// d = sqrtf( [ (x2 - x1)^2 + (y2 - y1)^2 + (z2 - z1)^2 ] )
	float result = 0.0f;

	float dx = v2.x - v1.x;
	float dy = v2.y - v1.y;
	float dz = v2.z - v1.z;

	result = (dx * dx) + (dy * dy) + (dz * dz);

	return result;
}

// angle between two vectors from origin (0, 0)
float Vec3Angle(const Vec3 v1, const Vec3 v2)
{
	// https://www.profajaypashankar.com/wp-content/uploads/2018/09/Mathematics-for-Computer-Graphics-Fifth-Edition.pdf
	// Page :: 116, 7.8.4 Angle between two vectors
	
	float cos0 = (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z) / (sqrtf((v2.x * v2.x) + (v2.y * v2.y) + (v2.z * v2.z)) * sqrtf((v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z)));
	return acosf(cos0) * RAD2DEG;
}

// return normalized vector
Vec3 Vec3Normalize(const Vec3 v)
{
	Vec3 result = v;

	float length = Vec3Length(v);
	if (length != 0.0f)
	{
		float ilength = 1.0f / length;

		result.x *= ilength;
		result.y *= ilength;
		result.z *= ilength;
	}

	return result;
}

// transform a vector by given matrix
Vec3 Vec3Transform(Vec3 v, Mat4x4 m)
{
	Vec3 result = Vec3Zero();

	float x = v.x;
	float y = v.y;
	float z = v.z;

	result.x = m.m0 * x + m.m4 * y + m.m8 * z + m.m12;
	result.y = m.m1 * x + m.m5 * y + m.m9 * z + m.m13;
	result.z = m.m2 * x + m.m6 * y + m.m10 * z + m.m14;

	return result;
}

// linear interpolation between two vectors by amount
Vec3 Vec3Lerp(const Vec3 v1, const Vec3 v2, float amount)
{
	Vec3 result = Vec3Zero();

	result.x = Lerp(v1.x, v2.x, amount);
	result.y = Lerp(v1.y, v2.y, amount);
	result.z = Lerp(v1.z, v2.z, amount);

	return result;
}

// calculate reflected vector to normal
Vec3 Vec3Reflect(const Vec3 v, const Vec3 normal)
{
	Vec3 result = Vec3Zero();

	float dp = Vec3DotProduct(v, normal);

	result.x = v.x - (2.0f * normal.x) * dp;
	result.y = v.y - (2.0f * normal.y) * dp;
	result.z = v.z - (2.0f * normal.z) * dp;

	return result;
}

// calculate projection of the v1 on to v2
Vec3 Vec3Project(const Vec3 v1, const Vec3 v2)
{
	Vec3 result = Vec3Zero();

	float v1dv2 = Vec3DotProduct(v1, v2);
	float v2dv2 = Vec3DotProduct(v2, v2);
	
	float mag = v1dv2 / v2dv2;

	result.x = v2.x * mag;
	result.y = v2.y * mag;
	result.z = v2.z * mag;

	return result;
}

// calculate rejection of the v1 on to v2
Vec3 Vec3Reject(const Vec3 v1, const Vec3 v2)
{
	Vec3 result = Vec3Zero();

	float v1dv2 = Vec3DotProduct(v1, v2);
	float v2dv2 = Vec3DotProduct(v2, v2);
	
	float mag = v1dv2 / v2dv2;

	result.x = v1.x - (v2.x * mag);
	result.y = v1.y - (v2.y * mag);
	result.z = v1.z - (v2.z * mag);

	return result;
}

// rotate by quaternion
Vec3 Vec3RotateByQuaternion(const Vec3 v, const Quaternion q)
{
	// https://www.euclideanspace.com/maths/algebra/realNormedAlgebra/quaternions/transforms/derivations/vectors/index.html

	Vec3 result = Vec3Zero();

	result.x = v.x * (q.x * q.x + q.w * q.w - q.y * q.y - q.z * q.z) 	+ v.y * (2 * q.x * q.y - 2 * q.w * q.z) 								+ v.z * (2 * q.x * q.z + 2 * q.w * q.y);
	result.y = v.x * (2 * q.w * q.z + 2 * q.x * q.y) 									+ v.y * (q.w * q.w - q.x * q.x + q.y * q.y - q.z * q.z) + v.z * (-2 * q.w * q.x + 2 * q.y * q.z);
	result.z = v.x * (-2 * q.w * q.y + 2 * q.x * q.z) 								+ v.y * (2 * q.w * q.x + 2 * q.y * q.z) 								+ v.z * (q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z);

	return result;
}

// rotates a vector around an axis
Vec3 Vec3RotateByAxisAngle(Vec3 v, Vec3 axis, float angle)
{
	// https://en.wikipedia.org/wiki/Euler%E2%80%93Rodrigues_formula

	Vec3 result = Vec3Zero();

	return result;
}

/*
	/////////////////////////////////////////////////////////
	///
	///	Vector 4 Related functions
	///
	/////////////////////////////////////////////////////////
*/

// returns Vec4 with components being 0.0f
Vec4 Vec4Zero(void)
{
	return (Vec4) { 0.0f, 0.0f, 0.0f, 0.0f };
}

// returns Vec4 with components being 1.0f
Vec4 Vec4One(void)
{
	return (Vec4) { 1.0f, 1.0f, 1.0f, 1.0f };
}

// returns addition of two vector
Vec4 Vec4Add(const Vec4 v1, const Vec4 v2)
{
	return (Vec4) { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w };
}

// returns addition in Vector with imm value
Vec4 Vec4AddV(const Vec4 v, float f)
{
	return (Vec4) { v.x + f, v.y + f, v.z + f, v.w + f };
}

// returns subtraction of two vector
Vec4 Vec4Sub(const Vec4 v1, const Vec4 v2)
{
	return (Vec4) { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w };
}

// returns subtraction in Vector with imm value
Vec4 Vec4SubV(const Vec4 v, float f)
{
	return (Vec4) { v.x - f, v.y - f, v.z - f, v.w - f };
}

// multiply by scale
Vec4 Vec4Scale(const Vec4 v, float f)
{
	return (Vec4) { v.x * f, v.y * f, v.z * f, v.w * f };
}

// multiply two vectors
Vec4 Vec4Multiply(const Vec4 v1, const Vec4 v2)
{
	return (Vec4) { v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w };
}

// divide two vectors
Vec4 Vec4Divide(const Vec4 v1, const Vec4 v2)
{
	return (Vec4) { v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w };
}

// calculate vector length
float Vec4Length(const Vec4 v)
{
	float result = sqrtf((v.x*v.x) + (v.y*v.y) + (v.z*v.z) + (v.w*v.w));
	return result;
}

// calculate dot prod of two vectors
float Vec4DotProduct(const Vec4 v1, const Vec4 v2)
{
	float result = (v1.x*v2.x + v1.y*v2.y + v1.z*v2.z + v1.w*v2.w);
	return result;
}

// distance between two vectors
float Vec4Distance(const Vec4 v1, const Vec4 v2)
{
	float result = sqrtf((v1.x - v2.x)*(v1.x - v2.x) + (v1.y - v2.y)*(v1.y - v2.y) + (v1.z - v2.z)*(v1.z - v2.z) + (v1.w - v2.w)*(v1.w - v2.w));
	return result;
}

// return normalized vector
Vec4 Vec4Normalize(const Vec4 v)
{
	Vec4 result = { 0 };
	float length = sqrtf((v.x*v.x) + (v.y*v.y) + (v.z*v.z) + (v.w*v.w));

	if (length > 0)
	{
		float ilength = 1.0f/length;
		result.x = v.x*ilength;
		result.y = v.y*ilength;
		result.z = v.z*ilength;
		result.w = v.w*ilength;
	}

	return result;
}

// linear interpolation between two vectors by amount
Vec4 Vec4Lerp(const Vec4 v1, const Vec4 v2, float amount)
{
	Vec4 result = Vec4Zero();

	result.x = Lerp(v1.x, v2.x, amount);
	result.y = Lerp(v1.y, v2.y, amount);
	result.z = Lerp(v1.z, v2.z, amount);
	result.w = Lerp(v1.w, v2.w, amount);

	return result;
}

/*
	/////////////////////////////////////////////////////////
	///
	///	Matrix Related functions
	///
	/////////////////////////////////////////////////////////
*/

float *MatrixMultiply(float *A, float *B, size_t Ar, size_t Ac, size_t Br, size_t Bc)
{
	float *result = malloc((Ar * Br) * sizeof(float));
	for (int i = 0; i < Bc; ++i) for (int j = 0; j < Ac; ++j) for (int k = 0; k < Ar; ++k) result[j] += A[k + j * Ac] * B[k + i * Br];

	return result;
}

// compute matrix determinant
float Mat4x4Determinant(Mat4x4 m)
{
	float result = 0.0f;

	// Cache the matrix values (speed optimization)
	float a00 = m.m0, a01 = m.m1, a02 = m.m2, a03 = m.m3;
	float a10 = m.m4, a11 = m.m5, a12 = m.m6, a13 = m.m7;
	float a20 = m.m8, a21 = m.m9, a22 = m.m10, a23 = m.m11;
	float a30 = m.m12, a31 = m.m13, a32 = m.m14, a33 = m.m15;

	result = a30*a21*a12*a03 - a20*a31*a12*a03 - a30*a11*a22*a03 + a10*a31*a22*a03 +
					 a20*a11*a32*a03 - a10*a21*a32*a03 - a30*a21*a02*a13 + a20*a31*a02*a13 +
					 a30*a01*a22*a13 - a00*a31*a22*a13 - a20*a01*a32*a13 + a00*a21*a32*a13 +
					 a30*a11*a02*a23 - a10*a31*a02*a23 - a30*a01*a12*a23 + a00*a31*a12*a23 +
					 a10*a01*a32*a23 - a00*a11*a32*a23 - a20*a11*a02*a33 + a10*a21*a02*a33 +
					 a20*a01*a12*a33 - a00*a21*a12*a33 - a10*a01*a22*a33 + a00*a11*a22*a33;

	return result;
}

// get the sum of values along diagonal
float Mat4x4SumAlongDiag(Mat4x4 m)
{
	float result = (m.m0 + m.m5 + m.m10 + m.m15);

	return result;
}

// transpose of a matrix
Mat4x4 Mat4x4Transpose(Mat4x4 m)
{
	Mat4x4 result = { 0 };

	result.m0 = m.m0;
	result.m1 = m.m4;
	result.m2 = m.m8;
	result.m3 = m.m12;
	result.m4 = m.m1;
	result.m5 = m.m5;
	result.m6 = m.m9;
	result.m7 = m.m13;
	result.m8 = m.m2;
	result.m9 = m.m6;
	result.m10 = m.m10;
	result.m11 = m.m14;
	result.m12 = m.m3;
	result.m13 = m.m7;
	result.m14 = m.m11;
	result.m15 = m.m15;

	return result;
}

// invert of a matrix
Mat4x4 Mat4x4Invert(Mat4x4 m)
{
	Mat4x4 result = { 0 };

	// Cache the mrix values (speed optimization)
	float a00 = m.m0, a01 = m.m1, a02 = m.m2, a03 = m.m3;
	float a10 = m.m4, a11 = m.m5, a12 = m.m6, a13 = m.m7;
	float a20 = m.m8, a21 = m.m9, a22 = m.m10, a23 = m.m11;
	float a30 = m.m12, a31 = m.m13, a32 = m.m14, a33 = m.m15;

	float b00 = a00*a11 - a01*a10;
	float b01 = a00*a12 - a02*a10;
	float b02 = a00*a13 - a03*a10;
	float b03 = a01*a12 - a02*a11;
	float b04 = a01*a13 - a03*a11;
	float b05 = a02*a13 - a03*a12;
	float b06 = a20*a31 - a21*a30;
	float b07 = a20*a32 - a22*a30;
	float b08 = a20*a33 - a23*a30;
	float b09 = a21*a32 - a22*a31;
	float b10 = a21*a33 - a23*a31;
	float b11 = a22*a33 - a23*a32;

	// Calculate the invert determinant (inlined to avoid double-caching)
	float invDet = 1.0f/(b00*b11 - b01*b10 + b02*b09 + b03*b08 - b04*b07 + b05*b06);

	result.m0 = (a11*b11 - a12*b10 + a13*b09)*invDet;
	result.m1 = (-a01*b11 + a02*b10 - a03*b09)*invDet;
	result.m2 = (a31*b05 - a32*b04 + a33*b03)*invDet;
	result.m3 = (-a21*b05 + a22*b04 - a23*b03)*invDet;
	result.m4 = (-a10*b11 + a12*b08 - a13*b07)*invDet;
	result.m5 = (a00*b11 - a02*b08 + a03*b07)*invDet;
	result.m6 = (-a30*b05 + a32*b02 - a33*b01)*invDet;
	result.m7 = (a20*b05 - a22*b02 + a23*b01)*invDet;
	result.m8 = (a10*b10 - a11*b08 + a13*b06)*invDet;
	result.m9 = (-a00*b10 + a01*b08 - a03*b06)*invDet;
	result.m10 = (a30*b04 - a31*b02 + a33*b00)*invDet;
	result.m11 = (-a20*b04 + a21*b02 - a23*b00)*invDet;
	result.m12 = (-a10*b09 + a11*b07 - a12*b06)*invDet;
	result.m13 = (a00*b09 - a01*b07 + a02*b06)*invDet;
	result.m14 = (-a30*b03 + a31*b01 - a32*b00)*invDet;
	result.m15 = (a20*b03 - a21*b01 + a22*b00)*invDet;

	return result;
}

// identity matrix 
Mat4x4 Mat4x4Identity(void)
{
	Mat4x4 result = { 1.0f, 0.0f, 0.0f, 0.0f,
										0.0f, 1.0f, 0.0f, 0.0f,
										0.0f, 0.0f, 1.0f, 0.0f,
										0.0f, 0.0f, 0.0f, 1.0f };

	return result;
}

// addition of two matrix
Mat4x4 Mat4x4Add(Mat4x4 m1, Mat4x4 m2)
{
	Mat4x4 result = { 0 };

	result.m0 = m1.m0 + m2.m0;
	result.m1 = m1.m1 + m2.m1;
	result.m2 = m1.m2 + m2.m2;
	result.m3 = m1.m3 + m2.m3;
	result.m4 = m1.m4 + m2.m4;
	result.m5 = m1.m5 + m2.m5;
	result.m6 = m1.m6 + m2.m6;
	result.m7 = m1.m7 + m2.m7;
	result.m8 = m1.m8 + m2.m8;
	result.m9 = m1.m9 + m2.m9;
	result.m10 = m1.m10 + m2.m10;
	result.m11 = m1.m11 + m2.m11;
	result.m12 = m1.m12 + m2.m12;
	result.m13 = m1.m13 + m2.m13;
	result.m14 = m1.m14 + m2.m14;
	result.m15 = m1.m15 + m2.m15;

	return result;
}

// subtraction of two matrix 
Mat4x4 Mat4x4Subtract(Mat4x4 m1, Mat4x4 m2)
{
	Mat4x4 result = { 0 };

	result.m0 = m1.m0 - m2.m0;
	result.m1 = m1.m1 - m2.m1;
	result.m2 = m1.m2 - m2.m2;
	result.m3 = m1.m3 - m2.m3;
	result.m4 = m1.m4 - m2.m4;
	result.m5 = m1.m5 - m2.m5;
	result.m6 = m1.m6 - m2.m6;
	result.m7 = m1.m7 - m2.m7;
	result.m8 = m1.m8 - m2.m8;
	result.m9 = m1.m9 - m2.m9;
	result.m10 = m1.m10 - m2.m10;
	result.m11 = m1.m11 - m2.m11;
	result.m12 = m1.m12 - m2.m12;
	result.m13 = m1.m13 - m2.m13;
	result.m14 = m1.m14 - m2.m14;
	result.m15 = m1.m15 - m2.m15;

	return result;
}

// multiplication of two matrix 
Mat4x4 Mat4x4Multiply(Mat4x4 m1, Mat4x4 m2)
{
	Mat4x4 result = { 0 };

	result.m0 = m1.m0*m2.m0 + m1.m1*m2.m4 + m1.m2*m2.m8 + m1.m3*m2.m12;
	result.m1 = m1.m0*m2.m1 + m1.m1*m2.m5 + m1.m2*m2.m9 + m1.m3*m2.m13;
	result.m2 = m1.m0*m2.m2 + m1.m1*m2.m6 + m1.m2*m2.m10 + m1.m3*m2.m14;
	result.m3 = m1.m0*m2.m3 + m1.m1*m2.m7 + m1.m2*m2.m11 + m1.m3*m2.m15;
	result.m4 = m1.m4*m2.m0 + m1.m5*m2.m4 + m1.m6*m2.m8 + m1.m7*m2.m12;
	result.m5 = m1.m4*m2.m1 + m1.m5*m2.m5 + m1.m6*m2.m9 + m1.m7*m2.m13;
	result.m6 = m1.m4*m2.m2 + m1.m5*m2.m6 + m1.m6*m2.m10 + m1.m7*m2.m14;
	result.m7 = m1.m4*m2.m3 + m1.m5*m2.m7 + m1.m6*m2.m11 + m1.m7*m2.m15;
	result.m8 = m1.m8*m2.m0 + m1.m9*m2.m4 + m1.m10*m2.m8 + m1.m11*m2.m12;
	result.m9 = m1.m8*m2.m1 + m1.m9*m2.m5 + m1.m10*m2.m9 + m1.m11*m2.m13;
	result.m10 = m1.m8*m2.m2 + m1.m9*m2.m6 + m1.m10*m2.m10 + m1.m11*m2.m14;
	result.m11 = m1.m8*m2.m3 + m1.m9*m2.m7 + m1.m10*m2.m11 + m1.m11*m2.m15;
	result.m12 = m1.m12*m2.m0 + m1.m13*m2.m4 + m1.m14*m2.m8 + m1.m15*m2.m12;
	result.m13 = m1.m12*m2.m1 + m1.m13*m2.m5 + m1.m14*m2.m9 + m1.m15*m2.m13;
	result.m14 = m1.m12*m2.m2 + m1.m13*m2.m6 + m1.m14*m2.m10 + m1.m15*m2.m14;
	result.m15 = m1.m12*m2.m3 + m1.m13*m2.m7 + m1.m14*m2.m11 + m1.m15*m2.m15;

	return result;
}

// get translation matrix
Mat4x4 Mat4x4Translation(const Vec3 v)
{
	Mat4x4 result = { 1.0f, 0.0f, 0.0f, v.x,
										0.0f, 1.0f, 0.0f, v.y,
										0.0f, 0.0f, 1.0f, v.z,
										0.0f, 0.0f, 0.0f, 1.0f };

	return result;
}

// rotation matrix from axis and angle
Mat4x4 Mat4x4Rotate(const Vec3 axis, float angle)
{
	Mat4x4 result = { 0 };

	float x = axis.x, y = axis.y, z = axis.z;

	float lengthSquared = x*x + y*y + z*z;

	if ((lengthSquared != 1.0f) && (lengthSquared != 0.0f))
	{
		float ilength = 1.0f/sqrtf(lengthSquared);
		x *= ilength;
		y *= ilength;
		z *= ilength;
	}

	float sinres = sinf(angle);
	float cosres = cosf(angle);
	float t = 1.0f - cosres;

	result.m0 = x*x*t + cosres;
	result.m1 = y*x*t + z*sinres;
	result.m2 = z*x*t - y*sinres;
	result.m3 = 0.0f;

	result.m4 = x*y*t - z*sinres;
	result.m5 = y*y*t + cosres;
	result.m6 = z*y*t + x*sinres;
	result.m7 = 0.0f;

	result.m8 = x*z*t + y*sinres;
	result.m9 = y*z*t - x*sinres;
	result.m10 = z*z*t + cosres;
	result.m11 = 0.0f;

	result.m12 = 0.0f;
	result.m13 = 0.0f;
	result.m14 = 0.0f;
	result.m15 = 1.0f;

	return result;
}

// get prespective projection matrix
Mat4x4 Mat4x4Frustum(double left, double right, double bottom, double top, double near, double far)
{
	Mat4x4 result = { 0 };

	float rl = (float)(right - left);
	float tb = (float)(top - bottom);
	float fn = (float)(far - near);

	result.m0 = ((float)near*2.0f)/rl;
	result.m1 = 0.0f;
	result.m2 = 0.0f;
	result.m3 = 0.0f;

	result.m4 = 0.0f;
	result.m5 = ((float)near*2.0f)/tb;
	result.m6 = 0.0f;
	result.m7 = 0.0f;

	result.m8 = ((float)right + (float)left)/rl;
	result.m9 = ((float)top + (float)bottom)/tb;
	result.m10 = -((float)far + (float)near)/fn;
	result.m11 = -1.0f;

	result.m12 = 0.0f;
	result.m13 = 0.0f;
	result.m14 = -((float)far*(float)near*2.0f)/fn;
	result.m15 = 0.0f;

	return result;
}

// get prespective projection matrix
Mat4x4 Mat4x4Prespective(double fov, double aspect, double near, double far)
{
	Mat4x4 result = { 0 };

	double top = near*tan(fov*0.5);
	double bottom = -top;
	double right = top*aspect;
	double left = -right;

	// MatrixFrustum(-right, right, -top, top, near, far);
	float rl = (float)(right - left);
	float tb = (float)(top - bottom);
	float fn = (float)(far- near);

	result.m0 = ((float)near*2.0f)/rl;
	result.m5 = ((float)near*2.0f)/tb;
	result.m8 = ((float)right + (float)left)/rl;
	result.m9 = ((float)top + (float)bottom)/tb;
	result.m10 = -((float)far + (float)near)/fn;
	result.m11 = -1.0f;
	result.m14 = -((float)far*(float)near*2.0f)/fn;

	return result;
}

// get orthographic projection matrix
Mat4x4 Mat4x4Ortho(double left, double right, double bottom, double top, double near, double far)
{
	Mat4x4 result = { 0 };

	float rl = (float)(right - left);
	float tb = (float)(top - bottom);
	float fn = (float)(far - near);

	result.m0 = 2.0f/rl;
	result.m1 = 0.0f;
	result.m2 = 0.0f;
	result.m3 = 0.0f;
	result.m4 = 0.0f;
	result.m5 = 2.0f/tb;
	result.m6 = 0.0f;
	result.m7 = 0.0f;
	result.m8 = 0.0f;
	result.m9 = 0.0f;
	result.m10 = -2.0f/fn;
	result.m11 = 0.0f;
	result.m12 = -((float)left + (float)right)/rl;
	result.m13 = -((float)top + (float)bottom)/tb;
	result.m14 = -((float)far+ (float)near)/fn;
	result.m15 = 1.0f;

	return result;
}

// view matrix
Mat4x4 Mat4x4LookAt(const Vec3 from, const Vec3 to, const Vec3 up)
{
    Mat4x4 result = { 0 };

    float length = 0.0f;
    float ilength = 0.0f;

    // Vector3Subtract(eye, target)
    Vec3 vz = { from.x - to.x, from.y - to.y, from.z - to.z };

    // Vector3Normalize(vz)
    Vec3 v = vz;
    length = sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
    if (length == 0.0f) length = 1.0f;
    ilength = 1.0f/length;
    vz.x *= ilength;
    vz.y *= ilength;
    vz.z *= ilength;

    // Vector3CrossProduct(up, vz)
    Vec3 vx = { up.y*vz.z - up.z*vz.y, up.z*vz.x - up.x*vz.z, up.x*vz.y - up.y*vz.x };

    // Vector3Normalize(x)
    v = vx;
    length = sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
    if (length == 0.0f) length = 1.0f;
    ilength = 1.0f/length;
    vx.x *= ilength;
    vx.y *= ilength;
    vx.z *= ilength;

    // Vector3CrossProduct(vz, vx)
    Vec3 vy = { vz.y*vx.z - vz.z*vx.y, vz.z*vx.x - vz.x*vx.z, vz.x*vx.y - vz.y*vx.x };

    result.m0 = vx.x;
    result.m1 = vy.x;
    result.m2 = vz.x;
    result.m3 = 0.0f;
    result.m4 = vx.y;
    result.m5 = vy.y;
    result.m6 = vz.y;
    result.m7 = 0.0f;
    result.m8 = vx.z;
    result.m9 = vy.z;
    result.m10 = vz.z;
    result.m11 = 0.0f;
    result.m12 = -(vx.x*from.x + vx.y*from.y + vx.z*from.z);   // Vector3DotProduct(vx, from)
    result.m13 = -(vy.x*from.x + vy.y*from.y + vy.z*from.z);   // Vector3DotProduct(vy, from)
    result.m14 = -(vz.x*from.x + vz.y*from.y + vz.z*from.z);   // Vector3DotProduct(vz, from)
    result.m15 = 1.0f;

    return result;
}

// matrix to float array
float16 Mat4x4ToFloat(const Mat4x4 m)
{
	float16 result = { 0 };

	result.v[0] = m.m0;
	result.v[1] = m.m1;
	result.v[2] = m.m2;
	result.v[3] = m.m3;
	result.v[4] = m.m4;
	result.v[5] = m.m5;
	result.v[6] = m.m6;
	result.v[7] = m.m7;
	result.v[8] = m.m8;
	result.v[9] = m.m9;
	result.v[10] = m.m10;
	result.v[11] = m.m11;
	result.v[12] = m.m12;
	result.v[13] = m.m13;
	result.v[14] = m.m14;
	result.v[15] = m.m15;

	return result;
}

/*
	/////////////////////////////////////////////////////////
	///
	///	Quaternion Related functions
	///
	/////////////////////////////////////////////////////////
*/

// add two quaternion
Quaternion QuaternionAdd(const Quaternion q1, const Quaternion q2)
{
	Quaternion result = {q1.x + q2.x, q1.y + q2.y, q1.z + q2.z, q1.w + q2.w};

	return result;
}

// add quaternion and value
Quaternion QuaternionAddValue(const Quaternion q, float f)
{
	Quaternion result = {q.x + f, q.y + f, q.z + f, q.w + f};

	return result;
}

// sub two quaternion
Quaternion QuaternionSubtract(const Quaternion q1, const Quaternion q2)
{
	Quaternion result = {q1.x - q2.x, q1.y - q2.y, q1.z - q2.z, q1.w - q2.w};

	return result;
}

// sub quaternion and value
Quaternion QuaternionSubtractValue(const Quaternion q, float f)
{
	Quaternion result = {q.x - f, q.y - f, q.z - f, q.w - f};

	return result;
}

// quaternion identity
Quaternion QuaternionIdentity(void)
{
	Quaternion result = { 0.0f, 0.0f, 0.0f, 1.0f };

	return result;
}

// length of quaternion
float QuaternionLength(const Quaternion q)
{
	float result = sqrtf(q.x*q.x + q.y*q.y + q.z*q.z + q.w*q.w);

	return result;
}

// normalize quaternion
Quaternion QuaternionNormalize(const Quaternion q)
{
	Quaternion result = { 0 };

	float length = sqrtf(q.x*q.x + q.y*q.y + q.z*q.z + q.w*q.w);
	if (length == 0.0f) length = 1.0f;
	float ilength = 1.0f/length;

	result.x = q.x*ilength;
	result.y = q.y*ilength;
	result.z = q.z*ilength;
	result.w = q.w*ilength;

	return result;
}

// invert quaternion
Quaternion QuaternionInvert(const Quaternion q)
{
	Quaternion result = q;

	float lengthSq = q.x*q.x + q.y*q.y + q.z*q.z + q.w*q.w;

	if (lengthSq != 0.0f)
	{
		float invLength = 1.0f/lengthSq;

		result.x *= -invLength;
		result.y *= -invLength;
		result.z *= -invLength;
		result.w *= invLength;
	}

	return result;
}

// multiply of two quaternion
Quaternion QuaternionMultiply(const Quaternion q1, const Quaternion q2)
{
	Quaternion result = { 0 };

	float qax = q1.x, qay = q1.y, qaz = q1.z, qaw = q1.w;
	float qbx = q2.x, qby = q2.y, qbz = q2.z, qbw = q2.w;

	result.x = qax*qbw + qaw*qbx + qay*qbz - qaz*qby;
	result.y = qay*qbw + qaw*qby + qaz*qbx - qax*qbz;
	result.z = qaz*qbw + qaw*qbz + qax*qby - qay*qbx;
	result.w = qaw*qbw - qax*qbx - qay*qby - qaz*qbz;

	return result;
}

// scale quaternion by a value
Quaternion QuaternionScale(const Quaternion q, float f)
{
	Quaternion result = { 0 };

	result.x = q.x*f;
	result.y = q.y*f;
	result.z = q.z*f;
	result.w = q.w*f;

	return result;
}

// divide of two quaternion
Quaternion QuaternionDivide(const Quaternion q1, const Quaternion q2)
{
	Quaternion result = { q1.x/q2.x, q1.y/q2.y, q1.z/q2.z, q1.w/q2.w };

	return result;
}

// lerp between two quaternion
Quaternion QuaternionLerp(const Quaternion q1, const Quaternion q2, float amount)
{
	Quaternion result = { 0 };

	result.x = q1.x + amount*(q2.x - q1.x);
	result.y = q1.y + amount*(q2.y - q1.y);
	result.z = q1.z + amount*(q2.z - q1.z);
	result.w = q1.w + amount*(q2.w - q1.w);

	return result;
}

// calculate slerp-optimized interpolation between two quaternion
Quaternion QuaternionNlerp(const Quaternion q1, const Quaternion q2, float amount)
{
	Quaternion result = { 0 };

	// QuaternionLerp(q1, q2, amount)
	result.x = q1.x + amount*(q2.x - q1.x);
	result.y = q1.y + amount*(q2.y - q1.y);
	result.z = q1.z + amount*(q2.z - q1.z);
	result.w = q1.w + amount*(q2.w - q1.w);

	// QuaternionNormalize(q);
	Quaternion q = result;
	float length = sqrtf(q.x*q.x + q.y*q.y + q.z*q.z + q.w*q.w);
	if (length == 0.0f) length = 1.0f;
	float ilength = 1.0f/length;

	result.x = q.x*ilength;
	result.y = q.y*ilength;
	result.z = q.z*ilength;
	result.w = q.w*ilength;

	return result;
}

// calculate spherical linear interpolation between two quaternion
Quaternion QuaternionSlerp(Quaternion q1, Quaternion q2, float amount)
{
    Quaternion result = { 0 };

    float cosHalfTheta = q1.x*q2.x + q1.y*q2.y + q1.z*q2.z + q1.w*q2.w;

    if (cosHalfTheta < 0)
    {
			q2.x = -q2.x; q2.y = -q2.y; q2.z = -q2.z; q2.w = -q2.w;
			cosHalfTheta = -cosHalfTheta;
    }

    if (fabsf(cosHalfTheta) >= 1.0f) result = q1;
    else if (cosHalfTheta > 0.95f) result = QuaternionNlerp(q1, q2, amount);
    else
    {
			float halfTheta = acosf(cosHalfTheta);
			float sinHalfTheta = sqrtf(1.0f - cosHalfTheta*cosHalfTheta);

			if (fabsf(sinHalfTheta) < EPSILON)
			{
				result.x = (q1.x*0.5f + q2.x*0.5f);
				result.y = (q1.y*0.5f + q2.y*0.5f);
				result.z = (q1.z*0.5f + q2.z*0.5f);
				result.w = (q1.w*0.5f + q2.w*0.5f);
			}
			else
			{
				float ratioA = sinf((1 - amount)*halfTheta)/sinHalfTheta;
				float ratioB = sinf(amount*halfTheta)/sinHalfTheta;

				result.x = (q1.x*ratioA + q2.x*ratioB);
				result.y = (q1.y*ratioA + q2.y*ratioB);
				result.z = (q1.z*ratioA + q2.z*ratioB);
				result.w = (q1.w*ratioA + q2.w*ratioB);
			}
    }

    return result;
}

// quaternion from matrix
Quaternion QuaternionFromMatrix(const Mat4x4 m)
{
	Quaternion result = { 0 };

	float fourWSquaredMinus1 = m.m0  + m.m5 + m.m10;
	float fourXSquaredMinus1 = m.m0  - m.m5 - m.m10;
	float fourYSquaredMinus1 = m.m5  - m.m0 - m.m10;
	float fourZSquaredMinus1 = m.m10 - m.m0 - m.m5;

	int biggestIndex = 0;
	float fourBiggestSquaredMinus1 = fourWSquaredMinus1;
	if (fourXSquaredMinus1 > fourBiggestSquaredMinus1)
	{
		fourBiggestSquaredMinus1 = fourXSquaredMinus1;
		biggestIndex = 1;
	}

	if (fourYSquaredMinus1 > fourBiggestSquaredMinus1)
	{
		fourBiggestSquaredMinus1 = fourYSquaredMinus1;
		biggestIndex = 2;
	}

	if (fourZSquaredMinus1 > fourBiggestSquaredMinus1)
	{
		fourBiggestSquaredMinus1 = fourZSquaredMinus1;
		biggestIndex = 3;
	}

	float biggestVal = sqrtf(fourBiggestSquaredMinus1 + 1.0f)*0.5f;
	float mult = 0.25f/biggestVal;

	switch (biggestIndex)
	{
		case 0:
			result.w = biggestVal;
			result.x = (m.m6 - m.m9)*mult;
			result.y = (m.m8 - m.m2)*mult;
			result.z = (m.m1 - m.m4)*mult;
			break;
		case 1:
			result.x = biggestVal;
			result.w = (m.m6 - m.m9)*mult;
			result.y = (m.m1 + m.m4)*mult;
			result.z = (m.m8 + m.m2)*mult;
			break;
		case 2:
			result.y = biggestVal;
			result.w = (m.m8 - m.m2)*mult;
			result.x = (m.m1 + m.m4)*mult;
			result.z = (m.m6 + m.m9)*mult;
			break;
		case 3:
			result.z = biggestVal;
			result.w = (m.m1 - m.m4)*mult;
			result.x = (m.m8 + m.m2)*mult;
			result.y = (m.m6 + m.m9)*mult;
			break;
	}

	return result;
}

// get a matrix for a given quaternion
Mat4x4 QuaternionToMatrix(const Quaternion q)
{
	Mat4x4 result = { 1.0f, 0.0f, 0.0f, 0.0f,
										0.0f, 1.0f, 0.0f, 0.0f,
										0.0f, 0.0f, 1.0f, 0.0f,
										0.0f, 0.0f, 0.0f, 1.0f }; // MatrixIdentity()

	float a2 = q.x*q.x;
	float b2 = q.y*q.y;
	float c2 = q.z*q.z;
	float ac = q.x*q.z;
	float ab = q.x*q.y;
	float bc = q.y*q.z;
	float ad = q.w*q.x;
	float bd = q.w*q.y;
	float cd = q.w*q.z;

	result.m0 = 1 - 2*(b2 + c2);
	result.m1 = 2*(ab + cd);
	result.m2 = 2*(ac - bd);

	result.m4 = 2*(ab - cd);
	result.m5 = 1 - 2*(a2 + c2);
	result.m6 = 2*(bc + ad);

	result.m8 = 2*(ac + bd);
	result.m9 = 2*(bc - ad);
	result.m10 = 1 - 2*(a2 + b2);

	return result;
}

// get rotation for an angle and axis
Quaternion QuaternionFromAxisAngle(Vec3 axis, float angle)
{
	Quaternion result = { 0.0f, 0.0f, 0.0f, 1.0f };

	float axisLength = sqrtf(axis.x*axis.x + axis.y*axis.y + axis.z*axis.z);

	if (axisLength != 0.0f)
	{
		angle *= 0.5f;

		float length = 0.0f;
		float ilength = 0.0f;

		// Vector3Normalize(axis)
		Vec3 v = axis;
		length = sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
		if (length == 0.0f) length = 1.0f;
		ilength = 1.0f/length;
		axis.x *= ilength;
		axis.y *= ilength;
		axis.z *= ilength;

		float sinres = sinf(angle);
		float cosres = cosf(angle);

		result.x = axis.x*sinres;
		result.y = axis.y*sinres;
		result.z = axis.z*sinres;
		result.w = cosres;

		// QuaternionNormalize(q);
		Quaternion q = result;
		length = sqrtf(q.x*q.x + q.y*q.y + q.z*q.z + q.w*q.w);
		if (length == 0.0f) length = 1.0f;
		ilength = 1.0f/length;
		result.x = q.x*ilength;
		result.y = q.y*ilength;
		result.z = q.z*ilength;
		result.w = q.w*ilength;
	}

	return result;
}

// get the rotation angle and axis for a given quaternion
void QuaternionToAxisAngle(Quaternion q, Vec3 *outAxis, float *outAngle)
{
	if (fabsf(q.w) > 1.0f)
	{
		// QuaternionNormalize(q);
		float length = sqrtf(q.x*q.x + q.y*q.y + q.z*q.z + q.w*q.w);
		if (length == 0.0f) length = 1.0f;
		float ilength = 1.0f/length;

		q.x = q.x*ilength;
		q.y = q.y*ilength;
		q.z = q.z*ilength;
		q.w = q.w*ilength;
	}

	Vec3 resAxis = { 0.0f, 0.0f, 0.0f };
	float resAngle = 2.0f*acosf(q.w);
	float den = sqrtf(1.0f - q.w*q.w);

	if (den > EPSILON)
	{
		resAxis.x = q.x/den;
		resAxis.y = q.y/den;
		resAxis.z = q.z/den;
	}
	else
	{
		// This occurs when the angle is zero.
		// Not a problem: just set an arbitrary normalized axis.
		resAxis.x = 1.0f;
	}

	*outAxis = resAxis;
	*outAngle = resAngle;
}

// Get the quaternion equivalent to Euler angles
// NOTE: Rotation order is ZYX
Quaternion QuaternionFromEuler(float pitch, float yaw, float roll)
{
	Quaternion result = { 0 };

	float x0 = cosf(pitch*0.5f);
	float x1 = sinf(pitch*0.5f);
	float y0 = cosf(yaw*0.5f);
	float y1 = sinf(yaw*0.5f);
	float z0 = cosf(roll*0.5f);
	float z1 = sinf(roll*0.5f);

	result.x = x1*y0*z0 - x0*y1*z1;
	result.y = x0*y1*z0 + x1*y0*z1;
	result.z = x0*y0*z1 - x1*y1*z0;
	result.w = x0*y0*z0 + x1*y1*z1;

	return result;
}

// Get the Euler angles equivalent to quaternion (roll, pitch, yaw)
// NOTE: Angles are returned in a Vector3 struct in radians
Vec3 QuaternionToEuler(Quaternion q)
{
	Vec3 result = { 0 };

	// Roll (x-axis rotation)
	float x0 = 2.0f*(q.w*q.x + q.y*q.z);
	float x1 = 1.0f - 2.0f*(q.x*q.x + q.y*q.y);
	result.x = atan2f(x0, x1);

	// Pitch (y-axis rotation)
	float y0 = 2.0f*(q.w*q.y - q.z*q.x);
	y0 = y0 > 1.0f ? 1.0f : y0;
	y0 = y0 < -1.0f ? -1.0f : y0;
	result.y = asinf(y0);

	// Yaw (z-axis rotation)
	float z0 = 2.0f*(q.w*q.z + q.x*q.y);
	float z1 = 1.0f - 2.0f*(q.y*q.y + q.z*q.z);
	result.z = atan2f(z0, z1);

	return result;
}

// Transform a quaternion given a transformation matrix
Quaternion QuaternionTransform(Quaternion q, Mat4x4 mat)
{
    Quaternion result = { 0 };

    result.x = mat.m0*q.x + mat.m4*q.y + mat.m8*q.z + mat.m12*q.w;
    result.y = mat.m1*q.x + mat.m5*q.y + mat.m9*q.z + mat.m13*q.w;
    result.z = mat.m2*q.x + mat.m6*q.y + mat.m10*q.z + mat.m14*q.w;
    result.w = mat.m3*q.x + mat.m7*q.y + mat.m11*q.z + mat.m15*q.w;

    return result;
}
