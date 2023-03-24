#include <stdio.h>
#include <stdlib.h>

#define BITS_PER_BYTE		8
#define BITS_TO_LONGS(nr)	DIV_ROUND_UP(nr, BITS_PER_BYTE * sizeof(long))
#define DIV_ROUND_UP(n,d)	(((n) + (d) - 1) / (d))
#define __BITS_PER_LONG		32

static inline void set_bit(int nr, unsigned long* addr)
{
	addr[nr / __BITS_PER_LONG] |= 1UL << (nr % __BITS_PER_LONG);
}

static inline void clear_bit(int nr, unsigned long* addr)
{
	addr[nr / __BITS_PER_LONG] &= ~(1UL << (nr % __BITS_PER_LONG));
}

static inline int test_bit(unsigned int nr, const unsigned long* addr)
{
	return ((1UL << (nr % __BITS_PER_LONG)) &
		(((unsigned long*)addr)[nr / __BITS_PER_LONG])) != 0;
}

int main(int argc, char* argv[])
{
	unsigned long evbit[BITS_TO_LONGS(0x1f)] = {0};

	printf("sizeof evbit = %d\n",(int)(sizeof(evbit)/sizeof(*evbit)));
	set_bit(3, evbit);
	set_bit(4, evbit);
	printf("value = %d\n", evbit[0]);
	printf("%d\n", test_bit(4,evbit));
	clear_bit(4, evbit);
	printf("second value = %d\n", evbit[0]);
	printf("%d\n", test_bit(4, evbit));

	return 0;
}