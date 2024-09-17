#include "fastfib.h"
#include <stdio.h>
#include <time.h>

int main(int argc, char** argv)
{
	printf("Argc: %d\n", argc);
	printf("Exec: %s\n", argv[0]);
	if (argc != 2)
	{
		printf("\033[31m\nError: Executable %s requires exactly 2 arguments but %d were given.\n", argv[0], argc);
		return (-1);
	}

	clock_t start, end;
	double cputime;
	start =  clock();
	/* add fib testing functionality here */

	uint64_t res = fast_fib(atoi(argv[1]));
	
	end = clock();
	cputime = ((double)(end - start))/CLOCKS_PER_SEC;
	printf("Time taken: %f\n", cputime);
	printf("Fib: %ld\n", res);
	return (0);
}