// BISMILLAH

#include "bits/stdc++.h"

const int mxN = 1000006;
int factors[mxN];

void divisorsCount() {
	
	for (int i = 1; i < mxN; i++) {
		int num = i;
		factors[i] = 1;
		for (int p = 2; p*p <= num; p++) {
			int count = 0;
			while (num % p == 0) {
				count++;
				num /= p;
			}
			factors[i] *= (count+1);
		}
		if (num > 1) {
			factors[i] *= 2;
		}
	}
	
}

signed main() {
	//
}

/*

	formula: NOD = (PrimeFactor[1]+1)*(PrimeFactor[2]+1)...(PrimeFactor[N]+1)

*/