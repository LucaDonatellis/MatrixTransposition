#include <iostream>
#include <string>
#include <omp.h>

#define BLOCK_SIZE 64

using namespace std;

bool checkSymOMP(int n, float **matrix);
void matTransposeOMP(int n, float **matrix, float **result);
bool isTranspose(int n, float **matrix, float **result);

int main(int argc, char **argv)
{
	// Argument validation
	if (argc != 2)
	{
		cout << "Required one argument";
		return 0;
	}
	const int n = stoi(argv[1]);
	if (!(n > 0 && ((n & (n - 1)) == 0)))
	{
		cout << "Argument must be a power of 2";
		return 0;
	}
	// Matrix inizialization
	float **M = new float *[n];
	for (int i = 0; i < n; ++i)
	{
		M[i] = new float[n];
		for (int j = 0; j < n; ++j)
		{
			M[i][j] = i * n + j;
		}
	}
	// Matrix result declaration
	float **T = new float *[n];
	for (int i = 0; i < n; ++i)
	{
		T[i] = new float[n];
	}
	// Code execution
	double wstart = omp_get_wtime();

	if (!checkSymOMP(n, M))
	{
		matTransposeOMP(n, M, T);
	}

	double wend = omp_get_wtime();
	cout << "Execution time: " << (wend - wstart) << " seconds" << endl;
	// cout << isTranspose(n,M,T);

	return 0;
}

bool checkSymOMP(int n, float **matrix)
{
	const int blockSize = min(n, BLOCK_SIZE);
	bool sym = true;

#pragma omp parallel for reduction(&& : sym) schedule(static)
	for (int i = 0; i < n; i += blockSize)
	{
		for (int j = i; j < n; j += blockSize)
		{
			for (int y = i; y < i + blockSize; ++y)
			{
				for (int x = j; x < j + blockSize; ++x)
				{
					if (matrix[x][y] != matrix[y][x])
					{
						sym = false;
					}
				}
			}
		}
	}
	return sym;
}

void matTransposeOMP(int n, float **matrix, float **result)
{
	const int blockSize = min(n, BLOCK_SIZE);

#pragma omp parallel for collapse(2) schedule(static)
	for (int i = 0; i < n; i += blockSize)
	{
		for (int j = 0; j < n; j += blockSize)
		{
			for (int x = i; x < i + blockSize; ++x)
			{
				for (int y = j; y < j + blockSize; ++y)
				{
					result[y][x] = matrix[x][y];
				}
			}
		}
	}
}

bool isTranspose(int n, float **matrix, float **result)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (result[j][i] != matrix[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
