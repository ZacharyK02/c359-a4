/*
Linear congruential generator taken from
https://rosettacode.org/wiki/Linear_congruential_generator
*/
/* always assuming int is at least 32 bits */
int rand();
int rseed = 0;

inline void srand(int x)
{
	rseed = x;
}

#define MS_RAND 1
#ifndef MS_RAND
#define RAND_MAX ((1U << 31) - 1)

inline int rand()
{
	return rseed = (rseed * 1103515245 + 12345) & RAND_MAX;
}

#else /* MS rand */

#define RAND_MAX_32 ((1U << 31) - 1)
#define RAND_MAX ((1U << 15) - 1)

inline int rand(int rseed)
{
	return (rseed = (rseed * 214013 + 2531011) & RAND_MAX_32) >> 16;
}

#endif/* MS_RAND */