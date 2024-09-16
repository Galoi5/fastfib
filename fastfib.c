#include "fastfib.h"
#include <stdint.h>
#include <stdlib.h>

uint64_t	iterative_fib(uint64_t n)
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);

	uint64_t un = 0;
	uint64_t un1 = 1;
	uint64_t un2;

	while (n-1)
	{
		un2 = un1 + un;
		un = un1;
		un1 = un2;
		n--;
	}
	return (un2);
}	

uint64_t	recursive_fib(uint64_t n)
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	return (iterative_fib(n - 1) + iterative_fib(n - 2));
}

void		_matrix_expo_classic(uint64_t** mat, uint64_t n)
{
	while (n)
	{
		uint64_t	tl = mat[0][0];
		uint64_t	tr = mat[0][1];
		uint64_t	bl = mat[1][0];
		uint64_t	br = mat[1][1];

		mat[0][0] = tl*tl + tr*bl;
		mat[0][1] = tl*tr + tr*br;
		mat[1][0] = bl*tl + br*bl;
		mat[1][1] = bl*tr + br*br;
		n--;
	}
}

uint64_t	matrix_fib(uint64_t n)
{
	uint64_t**	arr;
	arr = malloc(sizeof(uint64_t*) * 2);
	arr[0] = malloc(sizeof(uint64_t) * 2);
	arr[1] = malloc(sizeof(uint64_t) * 2);
	arr[0][0] = 1; // top left
	arr[0][1] = 1; // top right
	arr[1][0] = 1; // bottom left
	arr[1][1] = 0; // bottom right
	_matrix_expo_classic(arr, n);
	return (arr[0][1]);
}

void fast_fib(uint64_t n, uint64_t res[])
{
	uint64_t MOD = 1000000007;
	uint64_t a,b,c,d;

    if (n == 0) 
	{
        res[0] = 0;
        res[1] = 1;
        return;
    }
    fast_fib((n / 2), res);
    a = res[0];
    b = res[1];
    c = 2 * b - a;
    if (c < 0)
        c += MOD;
    c = (a * c) % MOD;
    d = (a * a + b * b) % MOD;
    if (n % 2 == 0) 
	{
        res[0] = c;
        res[1] = d;
    }
    else 
	{
        res[0] = d;
        res[1] = c + d;
    }
	return;
}


