/*
 * sais.h for sais-lite
 * Copyright (c) 2008-2010 Yuta Mori All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef _SAIS_H
#define _SAIS_H 1

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "../lib/utils.h"

/* find the suffix array SA of T[0..n-1]
   use a working space (excluding T and SA) of at most 2n+O(lg n) */
  int_t sais(const unsigned char *T, int_t *SA, int_t *LCP, int_t n);

/* find the suffix array SA of T[0..n-1] in {0..k-1}^n
   use a working space (excluding T and SA) of at most MAX(4k,2n) */
int_t
sais_int(const int_t *T, int_t *SA, int_t n, int_t k);

/* burrows-wheeler transform */
int_t
sais_bwt(const unsigned char *T, unsigned char *U, int_t *A, int_t n);
int_t
sais_int_bwt(const int_t *T, int_t *U, int_t *A, int_t n, int_t k);


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* _SAIS_H */
