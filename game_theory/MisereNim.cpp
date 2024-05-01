// BISMILLAH

#include <bits/stdc++.h>

using ll = long long;

signed main() {
	int testCases=1;
	scanf("%d",&testCases);
	
	for (int T = 1; T <= testCases; T++) {
		int n; scanf("%d",&n);
		int ans = 0, greaterThanOne=0;
		
		for (int i = 0,x; i < n; i++) {
			scanf("%d",&x);
			if (x>1) greaterThanOne = 1;
			ans ^= x;
		}
		
		if (greaterThanOne==0) {
			ans = n&1 ? 0:1;
		}
		
		printf("Case %d: %s\n",T,ans?"Alice":"Bob");
		
	}
	
	return 0;
}

/**

simple Nim & unity case!

https://lightoj.com/problem/misere-nim

*/