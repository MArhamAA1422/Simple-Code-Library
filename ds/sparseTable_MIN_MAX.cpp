// BISMILLAH

#include "bits/stdc++.h"

const int mxN = 500005;

int sp[mxN][21], sp1[mxN][21];

int lim(int x) {
	int ans;
	for (int i = 20; i >= 0; i--) {
		if ((1<<i) <= x) {
			ans = i;
			break;
		}
	}
	return ans;
}

int MIN(int l, int r) {
	int m = lim(r-l+1);
	return std::min(sp[l][m], sp[r-(1<<m)+1][m]);
}

int MAX(int l, int r) {
	int m = lim(r-l+1);
	return std::max(sp1[l][m], sp1[r-(1<<m)+1][m]);
}

signed main() {
	int N = mxN;
	
	for (int j = 1; j <= 20; j++) {
    	for (int i = 1; i+(1<<(j))-1 <= N; i++) {
    		sp[i][j] = std::min(sp[i][j-1], sp[i+(1<<(j-1))][j-1]);
    		sp1[i][j] = std::max(sp1[i][j-1], sp1[i+(1<<(j-1))][j-1]);
    	}
    }
	
	//
}

/*

TESTED on CF

*/