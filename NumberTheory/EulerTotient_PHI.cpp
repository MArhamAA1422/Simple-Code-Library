// BISMILLAH

#include <bits/stdc++.h>

using ll = long long;
const int mxN = 1000006;

int PHI[mxN];

ll Phi_function(ll N) { // TIME COMPLEXITY O(sqrt(N))
	if (N==1) return 0;
	
	ll phi_N = N;
	bool x=false;
	
	while (N%2==0) {
		N /= 2;
		x = true;
	}
	
	if (x) phi_N -= phi_N/2;
	
	for (int i = 3; (ll)i*i <= N; i += 2) {
		x = false;
		while (N%i==0) {
			N /= i;
			x = true;
		}
		if (x) phi_N -= phi_N/i;
	}
	
	if (N>1) {
		phi_N -= phi_N/N;
	}
	
	return phi_N;
}

void totientUPtoN(int N) { // TIME COMPLEXITY O(lglgN)
	
	for (int i = 1; i <= N; i++) {
		PHI[i] = i;
	}
	
	PHI[1] = 0;
	for (int i = 2; i <= N; i++) {
		if (PHI[i]==i) {
			for (int j = i; j <= N; j += i) {
				PHI[j] -= PHI[j]/i;
			}
		}
	}
	
}

signed main() {
	totientUPtoN(mxN-1);
	
	for (int i = 1; i < mxN; i++) {
		if (Phi_function(i)!=PHI[i]) printf("%d\n",i);
	}
	
	return 0;
}

/**

TESTED LOCALLY

*/