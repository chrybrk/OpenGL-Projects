#include <stdio.h>
#include <stdlib.h>

/*
		// Column-major order
		x' = c00 * x + c01 * y + c02 * z;
		y' = c10 * x + c11 * y + c12 * z;
		z' = c20 * x + c21 * y + c22 * z;
*/

float *MatrixMultiply(float *A, float *B, size_t Ar, size_t Ac, size_t Br, size_t Bc)
{
	float *result = malloc((Ar * Br) * sizeof(float));
	for (int i = 0; i < Bc; ++i) for (int j = 0; j < Ac; ++j) for (int k = 0; k < Ar; ++k) result[j] += A[k + j * Ac] * B[k + i * Br];

	return result;
}

int main(void)
{
	float A[] = {
		10, 40, 70,
		20, 50, 80,
		30, 60, 90
	};

	float B[] = {
		100,
		200,
		300
	};

	/*
	 * [ 10 * 100 + 40 * 200 + 70 * 300 ] -> 30,000
	 * [ 20 * 100 + 50 * 200 + 80 * 300 ] -> 36,000
	 * [ 30 * 100 + 60 * 200 + 90 * 300 ] -> 42,000
	*/

	float *result = MatrixMultiply(A, B, 3, 3, 3, 1);
	for (int i = 0; i < 3 * 1; ++i)
	{
		printf("%f ", result[i]);
	}

	return 0;
}
