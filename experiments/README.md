# Experiments

This code implements a comparison between the algorithms SACA-K+LCP [1], SAIS+LCP [3] and SACA-K [2] combined with \Phi-algorithm [4] to compute the suffix and LCP arrays.

## Run:

To run a test type:

```sh
make
make run DIR=dataset INPUT=input.100.txt K=100 MODE=1
```

One can change to 32 bits integers (when n < 2^31) in lib/utils.h, setting m64 to 0.

**Settings:**

MODE parameter specifies which algorithm is called by main.c:

```sh
* 1: SACA-K+LCP 
* 2: SAIS+LCP [3]
* 3: SACA-K [2] and \Phi-algorithm [4] 
```
