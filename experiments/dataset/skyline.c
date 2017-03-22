/*
 * http://panthema.net/2012/1119-eSAIS-Inducing-Suffix-and-LCP-Arrays-in-External-Memory/eSAIS-DC3-LCP-0.5.0/src/input/skyline.h.html
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

#include "../lib/utils.h"

int main(int argc, char** argv){

uint_t n;

	sscanf(argv[1], "%d", &n);

	size_t i, log2len = ceil( log(n+1) / log(2) );

	for (i = 0; i < n; ++i){

		//count number of least-significant binary zeros in i+1
		size_t j = i+1;

		unsigned int zc = 0;

		while ( (j & 1) == 0 ) {
			zc++; j >>= 1;
		//	assert( j != 0 );
		}

		zc = min(zc, log2len - 1); // repeat a if size is not a power of 2

		printf("%c", 'a' + (log2len - zc - 1));
//		out[i] = 'a' + (log2len - zc - 1);
//		std::cout << i << " : " << (out[i] - 'a') << " - " << out[i] << "\n";
	}
printf("\n");

return 0;
}
