#sacak-lcp

This code is an implementation of SACA-K+LCP [1], which extends the
optimal suffix sorting algorithm SACA-K [2] to also compute the LCP array.


--
##run:

To run a test type:

```sh
make
make run DIR=dataset INPUT=input.100.txt K=100 MODE=1
```

One can change to 32 bits integers (when n < 2^31) in lib/utils.h, setting m64 to 0.

--
**Settings:**

MODE parameter specifies which algorithm is called by main.c:

* 1: SACA-K+LCP 
* 2: SAIS+LCP [3]
* 3: SACA-K [2] and \Phi-algorithm [4] 

--

##references

\[1\] Louza, F. A., Gog, S., Telles, G. P., Optimal suffix sorting and LCP array construction for constant alphabets (submitted).

\[2\] Nong, G., Practical linear-time O(1)-workspace suffix sorting for constant alphabets, ACM Trans. Inform. Syst., vol. 31, no. 3, pp. 1-15, 2013

\[3\] Fischer, J., Inducing the LCP-Array, in: Proc. WADS, 2011, pp. 374-385.

\[4\] Karkkainen, J., Manzini, G., Puglisi, S. J., Permuted longest-common-prefix array, in: Proc. CPM, Vol. 5577 of LNCS, Springer, 2009, pp. 181-192.
