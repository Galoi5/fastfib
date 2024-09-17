#include "fastfib.h"
#include <stdio.h>
#include <time.h>

int main()
{
	clock_t start, end;
	double cputime;
	start =  clock();
	/* add fib testing functionality here */

	uint64_t res = fast_fib(10);
	
	end = clock();
	cputime = ((double)(end - start))/CLOCKS_PER_SEC;
	printf("Time taken: %f\n", cputime);
	printf("Fib: %ld\n", res);

}