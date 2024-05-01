// BISMILLAH

#include <bits/stdc++.h>

using ll = long long;

const int mxN = 10001;
int G[mxN+5], used[mxN+5];

signed main() {
	int testCases=1;
	scanf("%d",&testCases);
	
	auto grundy = [&] () {
		int offset = 0;
		for (int i = 1; i < mxN; i++) {
			int lim = i/2; if (i%2==0) lim--;
			for (int j = 1,xorVal; j <= lim; j++) {
				xorVal = G[j]^G[i-j];
				used[xorVal] = offset+1;
			}
			int ok = 0; // MEX calculation helper
			for (int j = 0; j < 2*mxN; j++) {
				if (used[j]<=offset) {
					G[i] = j;
					ok = 1;
					break;
				}
			}
			if (ok==0) G[i] = 2*mxN;
			offset++;
		}
	};
	grundy();
	
	for (int T = 1; T <= testCases; T++) {
		int n; scanf("%d",&n);
		int ans = 0;
		
		for (int i = 0,x; i < n; i++) {
			scanf("%d",&x);
			ans ^= G[x];
		}
		
		printf("Case %d: %s\n",T,ans?"Alice":"Bob");
		
	}
	
	return 0;
}

/**

https://lightoj.com/problem/partitioning-game

*/