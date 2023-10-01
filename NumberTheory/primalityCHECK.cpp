// BISMILLAH

#include <bits/stdc++.h>

const int mxN = 1000006;

using ll = long long;

bool isPrime(ll x) {
	if (x==1) return false;
	if (x==2) return true;
	if (x%2==0) return false;
	
	for (int i = 3; (ll)i*i <= x; i += 2) {
		if (x%i==0) return false;
	}
	
	return true;
}

signed main() {
	while (true) {
		int N;
		scanf("%d",&N);
		printf("%s\n",isPrime(N)?"PRIME":"NOT PRIME");
	}
	
	return 0;
}

/**

TESTED LOCALLY

*/