// BISMILLAH

#include "bits/stdc++.h"

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define fastIO std::ios::sync_with_stdio(0);std::cin.tie(0)
#define ll long long int
#define flush fflush(stdout)
#define bl printf("\n")
// #define int ll

using pii = std::pair<int,int>;

const int MOD = 1000000007;
// const int MOD = 998244353;
const int mxN = 500005, inf = 1000000005;

int N;
ll dp[101][101], pre[101][101][101];
int a[101];

ll cost(int i, int j, int k) {
	return (ll)a[i]*a[j]*a[k];
}

signed main() {
	// fastIO;
	int testCases=1;
	scanf("%d",&testCases);
	// std::cin >> testCases;
	
	for (int T = 1; T <= testCases; T++) {
		scanf("%d",&N);
		for (int i = 1; i <= N; i++) scanf("%d",&a[i]);
		for (int len = 3; len <= N; len++) {
			for (int l = 1; l+len-1 <= N; l++) {
				int r = l+len-1;
				if (len == 3) {
					dp[l][r] = cost(l, l+1, l+2);
					continue;
				}
				ll ans = 1e18;
				for (int x = l+1; x <= r-1; x++) {
					if (x == l+1) {
						ans = std::min(ans, cost(l, x, r) + dp[x][r]);
					} else if (x == r-1) {
						ans = std::min(ans, cost(l, x, r) + dp[l][x]);
					} else {
						ans = std::min(ans, cost(l, x, r) + dp[l][x] + dp[x][r]);
					}
				}
				dp[l][r] = ans;
			}
		}
		printf("%lld\n", dp[1][N]);
	}
	
	return 0;
}

/*

	TESTED on- AlgoZenith

*/