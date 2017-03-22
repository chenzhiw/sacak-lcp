# sacak-lcp

SACA-K+LCP is an optimal suffix and LCP array construction algorithm for constant alphabets.

## Introduction

SACA-K+LCP \[1\] extends the optimal suffix sorting algorithm SACA-K [2] to also compute the LCP array for a string in linear time using O(\sigma \log n) bits of additional space (workspace). In practice, SACA-K+LCP uses 10KB additional space for strings from ASCII alphabet.


## Build requirements
An ANSI C Compiler (e.g. GNU GCC)


## API
```c
/** @brief computes the suffix and LCP arrays of string s[0..n-1] in {0..255}^n
 *
 *  @param s    input string with s[n-1]=0
 *  @param SA   suffix array 
 *  @param LCP  LCP array 
 *  @param n    string length
 *  @return -1 if an error occured, otherwise the depth of the recursive calls.
 */
int sacak_lcp(unsigned char *s, uint_t *SA, int_t* LCP, uint_t n);

/** @brief computes the suffix and LCP arrays of string s[0..n-1] in {0..k}^n
 *
 *  @param s    input string with s[n-1]=0
 *  @param SA   suffix array 
 *  @param LCP  LCP array 
 *  @param n    string length
 *  @return -1 if an error occured, otherwise the depth of the recursive calls.
 */
int sacak_lcp_int(int_t *s, uint_t *SA, int_t* LCP, uint_t n, uint_t k);
```

## Example

**Compilation:**

```sh
gcc -c sacak-lcp.c -o sacak-lcp.o
gcc -c experiments/external/malloc_count.c
gcc test.c -o test sacak-lcp.o malloc_count.o -ldl
```

**Run a test:**

```c
./test banaananaanana
```

**Output:**

```c
sizeof(int_t) = 4 bytes
Text = banaananaanana$
i	SA	LCP	BWT	suffixes
0	14	0	a	$
1	13	0	n	a$
2	8	1	n	aanana$
3	3	6	n	aananaanana$
4	11	1	n	ana$
5	6	3	n	anaanana$
6	1	8	b	anaananaanana$
7	9	3	a	anana$
8	4	5	a	ananaanana$
9	0	0	$	banaananaanana$
10	12	0	a	na$
11	7	2	a	naanana$
12	2	7	a	naananaanana$
13	10	2	a	nana$
14	5	4	a	nanaanana$
malloc_count ### exiting, total: 19,832, peak: 10,375, current: 0
```

**Remark:**

```
The peak memory 10,375 is exactly 10KB + 135 bytes.
10KB is the workspace and 135 (9\*15 bytes) bytes is the space used by the string s and the arrays SA and LCP (9\*n bytes)
```

**Strings larger than n=2^20:**

```t
One can change to 64 bits integers adding -DM64=1 in the compilation.
```
--

## References

\[1\] Louza, F. A., Gog, S., Telles, G. P., Optimal suffix sorting and LCP array construction for constant alphabets, Inf. Process. Lett. 118 (2017) 30-34, http://www.sciencedirect.com/science/article/pii/S0020019016301375

\[2\] Nong, G., Practical linear-time O(1)-workspace suffix sorting for constant alphabets, ACM Trans. Inform. Syst., vol. 31, no. 3, pp. 1-15, 2013

\[3\] Fischer, J., Inducing the LCP-Array, in: Proc. WADS, 2011, pp. 374-385.

\[4\] Karkkainen, J., Manzini, G., Puglisi, S. J., Permuted longest-common-prefix array, in: Proc. CPM, Vol. 5577 of LNCS, Springer, 2009, pp. 181-192.
