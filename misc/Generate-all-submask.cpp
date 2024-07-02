// BISMILLAH

#include "bits/stdc++.h"

signed main() {
	int testCases=1;
	// scanf("%d",&testCases);
	
	for (int T = 1; T <= testCases; T++) {
		int mask;
		scanf("%d", &mask);
		
		for (int i = 9; i >= 0; i--) {
			if (mask&(1<<i)) printf("1");
			else printf("0");
		}
		printf("\n\n");
		
		for (int submask = mask; submask; submask = (submask-1)&mask) {
			for (int i = 9; i >= 0; i--) {
				if (submask&(1<<i)) printf("1");
				else printf("0");
			}
			printf("\n");
		}
		
	}
	
	return 0;
}

/*

*/