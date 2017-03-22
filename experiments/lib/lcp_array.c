#include "lcp_array.h"

/*******************************************************************/

uint_t find_inverse(uint_t* SA, uint_t n, uint_t* A){
	
	uint_t i;
	for(i = 0; i < n; i++) A[SA[i]] = i;

return 0;
}

/*******************************************************************/

uint_t lcp_kasai(char* T, uint_t* SA, uint_t n, int_t* LCP){
	
	uint_t *I = (uint_t* ) malloc(n * sizeof(uint_t));
	find_inverse(SA, n, I);
	
	uint_t l = 0;
	uint_t j, k, i;
	
	for(i = 0; i < n; i++){

		k = I[i];
	
		if(!k) {
			LCP[k] = 0;
		}
		else{
			
			j = SA[k-1];
			while(T[i+l] == T[j+l] && !(T[i+l] == 0 && T[j+l]==0)){
				l++; 
			}
			
			LCP[k] = l;
			if(T[i+l] == 0 && T[j+l]==0) LCP[k]++;
			if(l>0) l--;
		}
	}	
	
	free(I);

return 0;
}

uint_t lcp_PHI(unsigned char* T, uint_t* SA, int_t* LCP, uint_t n){

	uint_t* PLCP = (uint_t*) malloc(n * sizeof(uint_t));;

	//PHI is stored in PLCP array
	uint_t i,j;
	for (i=0, j = 0; i < n; ++i) {
		PLCP[SA[i]] = j;
		j = SA[i];
	}

	int_t l;
	for (i=0, l=0; i < n-1; ++i) {
		while (T[i+l] == T[PLCP[i]+l] && !(T[i+l] == 0 && T[PLCP[i]+l]==0) ) {
		    ++l;
		}
		PLCP[i] = l;
		if (l) --l;
	}

	for (i=0; i < n; ++i) {
		LCP[i] = PLCP[SA[i]];
	}
	
	free(PLCP);

return 0;
}

/*******************************************************************/
int lcp_array_check(unsigned char *T, uint_t *SA, uint_t n1, int_t *LCP, uint_t n){
	
	uint_t i,j,k;
	uint_t h;
	double mean=0.0;

	for(i=1;i<n1;i++) {
		
		j=SA[i-1]; k=SA[i];
		for(h=0;j+h<n && k+h<n;h++) if(T[j+h]!=T[k+h]) break;
		
		if(LCP[i]!=h) {
			fprintf(stdout,"isNotLCP! Incorrect LCP value: LCP[%" PRIdN "]=%" PRIdN "!=%" PRIdN "\t(%" PRIdN ")\n", i, LCP[i],h, SA[i]);
			return 0;
		}
		mean+=(double)LCP[i]/(double)n1;
	}
	
	printf("LCP_mean = %lf\n", mean);
	
return 1;
}
/*******************************************************************/
