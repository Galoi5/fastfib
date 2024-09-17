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


uint64_t fast_fib(uint64_t n)
{
	uint64_t	h = 0; //highest bot of n (most left)
	uint64_t	mask;

	uint64_t	i = n;
	while (i)
	{
		++h;
		i>>=1;
	}

	uint64_t	a = 0;
	uint64_t	b = 1;
	uint64_t	c;
	uint64_t	d;
	mask = 1 << (h - 1);
	while (mask)
	{
		c = a * (2 * b - a);
		d = a * a + b * b;
		if (mask & n)
		{
			a = d;
			b = c + d;
		} 
		else
		{
			a = c;
			b = d;
		}
		mask >>= 1;
	}
	return (a);
}

