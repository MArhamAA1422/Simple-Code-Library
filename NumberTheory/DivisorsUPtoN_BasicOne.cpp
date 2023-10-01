// BISMILLAH

#include <bits/stdc++.h>

const int mxN = 1000006;

std::vector<int> factors[mxN];

void divisorsUPtoN(int N) {
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			factors[j].push_back(i);
		}
	}
}

signed main() {
	divisorsUPtoN(101);
	
	for (int i = 1; i <= 100; i++) {
		printf("%d - ",i);
		for (auto j : factors[i]) printf("%d ",j);
		printf("\n");
	}
	
	return 0;
}

/**

TESTED LOCALLY

*/