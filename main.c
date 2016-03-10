/*
 * Optimal suffix sorting and LCP array construction for constant alphabets
 *
 * Authors: Felipe A. Louza, Simon Gog, Guilherme P. Telles
 * contact: louza@ic.unicamp.br
 * 15/01/2016
 *
 */

#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <limits.h>

#include "lib/utils.h"
#include "lib/file.h"
#include "lib/suffix_array.h"
#include "lib/lcp_array.h"
#include "external/malloc_count/malloc_count.h"
#include "external/sais-lcp.h"
#include "src/sacak-lcp.h"

#define DEBUG 0 

/*******************************************************************/
unsigned char* cat_char(unsigned char** R, int k, int_t *n){

	(*n)++; //add 0 at the end

	int_t i, j;
	int_t l=0;
	unsigned char *str = (unsigned char*) malloc((*n)*sizeof(unsigned char));

	for(i=0; i<k; i++){
		int_t m = strlen((char*)R[i]);
		for(j=0; j<m; j++){
			if(R[i][j]<255) str[l++] = R[i][j]+1;
		}
		str[l++] = 1; //add 1 as separator
	}

	str[l++]=0;

	if(*n>l){
	  str = (unsigned char*) realloc(str, (l)*sizeof(unsigned char)); 
	  printf("str_realloc(%" PRIdN ", %" PRIdN ")\n", *n, l);
	}

	*n = l;

return str;
}

/*******************************************************************/

int main(int argc, char** argv){

time_t t_start=0, t_total=0;
clock_t c_start=0, c_total=0;

int VALIDATE=0, MODE=0, OUTPUT=0;

	if(argc!=7){
		dies(__func__,"argc!=4");
	}

	unsigned char **R;
	int_t i, n=0;
	int   k;

	char* c_dir = argv[1];
	char* c_file = argv[2];

	sscanf(argv[3], "%d", &k);
	sscanf(argv[4], "%u", &MODE);
	sscanf(argv[5], "%u", &VALIDATE);
	sscanf(argv[6], "%u", &OUTPUT);

	file_chdir(c_dir);

	//disk access
	R = (unsigned char**) file_load_multiple(c_file, k, &n);
	if(!R){
		fprintf(stderr, "Error: less than %d strings in %s\n", k, c_file);
		return 0;
	}

	//concatenate strings
	unsigned char *str = NULL;
	str = cat_char(R, k, &n);

	printf("K = %" PRId32 "\n", k);
	printf("N = %" PRIdN " bytes\n", n);
	printf("sizeof(int) = %zu bytes\n", sizeof(int_t));

	#if DEBUG
		printf("R:\n");
		for(i=0; i<k; i++)
			printf("%" PRIdN ") %s (%zu)\n", i, R[i], strlen((char*)R[i]));
	#endif

	//free memory
	for(i=0; i<k; i++)
		free(R[i]);
	free(R);

	//sorted array
	int_t *SA = (int_t*) malloc(n*sizeof(int_t));
	int_t *LCP = (int_t*) malloc(n*sizeof(int_t));

	for(i=0; i<n;i++) LCP[i]=0;

	int_t depth=0;

	time_start(&t_total, &c_total);

	switch(MODE){

		case 1: printf("## SACA_K+LCP ##\n"); 
			depth = SACA_K_LCP((int_t*)str, (uint_t*)SA, LCP, n, 256, n, sizeof(char), 0);
			break;

		case 2:	printf("## SAIS+LCP ##\n"); 
			depth = sais(str, (int_t*)SA, LCP, (int_t)n);
			break;

		case 3:	printf("## SACA_K and PHI ##\n"); 
			depth = SACA_K((int_t*)str, (uint_t*)SA, n, 256, n, sizeof(char), 0);
			//LCP-array
			time_start(&t_start, &c_start);
			lcp_PHI((unsigned char*)str, (uint_t*)SA, LCP, n);
			printf("PHI-algorithm:\n");
			fprintf(stderr,"%.6lf\n", time_stop(t_start, c_start));
			break;
		
		default: break;
	}

	printf("total:\n");
	fprintf(stderr,"%.6lf\n", time_stop(t_total, c_total));

	// validate	
	if(VALIDATE==1){
 	       	if(!suffix_array_check(SA, (unsigned char*)str, n, sizeof(char), 0)) printf("isNotSorted!!\n");
	        else printf("isSorted!!\ndepth = %" PRIdN "\n", depth);

	       	if(!lcp_array_check((unsigned char*)str, (uint_t*)SA, n, LCP, n)) printf("isNotLCP!!\n");
	        else printf("isLCP!!\n");
	}

	// output
	if(OUTPUT){
		suffix_array_write(SA, n, c_file, "sa");
	}

	#if DEBUG
		suffix_array_print(SA, (unsigned char*)str, min(10,n), sizeof(char));
	#endif


	free(SA);
	free(LCP);
	free(str);

return 0;
}

