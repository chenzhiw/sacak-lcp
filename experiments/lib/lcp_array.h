#ifndef LCPH
#define LCPH

#include <string.h>
#include <stdio.h>
#include <limits.h>

#include "utils.h"


/**
 * Constructs the lcp array of a given suffix array.
 * @param T[0..n-1] The input string.
 * @param SA[0..n-1] The input suffix array.
 * @param n The length of the given string.
 * @return 0 if no error occurred, -1 otherwise.
 */
uint_t lcp_kasai(char* T, uint_t* SA, uint_t n, int_t* LCP);

/**
 * Constructs the lcp array of a given suffix array.
 * @param T[0..n-1] The input string.
 * @param SA[0..n-1] The input suffix array.
 * @param n The length of the given string.
*/
uint_t lcp_PHI(unsigned char* T, uint_t* SA, int_t* LCP, uint_t n);

int lcp_array_check(unsigned char *T, uint_t *SA, uint_t n1, int_t *LCP, uint_t n);


#endif
