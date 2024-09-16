#if !defined(FASTFIB_C)
#define FASTFIB_C

#include <inttypes.h>

uint64_t	iterative_fib(uint64_t n);
uint64_t	recursive_fib(uint64_t n);
void		_matrix_expo_classic(uint64_t** mat, uint64_t n);
uint64_t	matrix_fib(uint64_t n);
void 		fast_fib(uint64_t n, uint64_t res[]);
uint64_t	karatsubafast_fib(uint64_t n); // fastfib with karatsuba multiplication

#endif // FASTFIB_C
