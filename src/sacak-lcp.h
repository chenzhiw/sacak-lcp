/* 
 * Authors: Felipe A. Louza, Simon Gog, Guilherme P. Telles
 * contact: louza@ic.unicamp.br
 * 15/01/2016
 */

/* 
 * This code is a modification of SACA-K algorithm by G. Nong, which can be
 * retrieved at: http://code.google.com/p/ge-nong/ 
 *
 * Our version of SACA-K, SACA-K+LCP, constructs the suffix array and the LCP array, maintaining the  
 * theoretical bounds of the original algorithm.
 *
 */


#ifndef SACA_K_H
#define SACA_K_H

#include <stdlib.h>
#include <stdio.h>

#include "../lib/utils.h"
#include "../lib/lcp_array.h"

int_t SACA_K(int_t *s, uint_t *SA, uint_t n, unsigned int K, uint_t m, int cs, int level);
int_t SACA_K_LCP(int_t *s, uint_t *SA, int_t *LCP, uint_t n, unsigned int K, uint_t m, int cs, int level);

#endif
