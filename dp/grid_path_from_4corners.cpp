// BISMILLAH

// Problem link: https://codeforces.com/contest/429/problem/B

#include "bits/stdc++.h"

#define ll long long int
const int mxN = 1005, inf = 1000000005;

int a[mxN][mxN];
ll dp[4][mxN][mxN];

signed main() {
	int testCases=1;
	
	for (int T = 1; T <= testCases; T++) {
		int N, M;
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		dp[0][0][0] = a[0][0];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (i-1 >= 0) dp[0][i][j] = std::max(dp[0][i][j], dp[0][i-1][j]+a[i][j]);
				if (j-1 >= 0) dp[0][i][j] = std::max(dp[0][i][j], dp[0][i][j-1]+a[i][j]);
			}
		}
		dp[1][0][M-1] = a[0][M-1];
		for (int i = 0; i < N; i++) {
			for (int j = M - 1; j >= 0; j--) {
				if (i-1 >= 0) dp[1][i][j] = std::max(dp[1][i][j], dp[1][i-1][j]+a[i][j]);
				if (j+1 < M) dp[1][i][j] = std::max(dp[1][i][j], dp[1][i][j+1]+a[i][j]);
			}
		}
		dp[2][N-1][M-1] = a[N-1][M-1];
		for (int i = N-1; i >= 0; i--) {
			for (int j = M-1; j >= 0; j--) {
				if (i+1 < N) dp[2][i][j] = std::max(dp[2][i][j], dp[2][i+1][j]+a[i][j]);
				if (j+1 < M) dp[2][i][j] = std::max(dp[2][i][j], dp[2][i][j+1]+a[i][j]);
			}
		}
		dp[3][N-1][0] = a[N-1][0];
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < M; j++) {
				if (i+1 < N) dp[3][i][j] = std::max(dp[3][i][j], dp[3][i+1][j]+a[i][j]);
				if (j-1 >= 0) dp[3][i][j] = std::max(dp[3][i][j], dp[3][i][j-1]+a[i][j]);
			}
		}
		ll ans = 0;
		for (int i = 1; i < N-1; i++) {
			for (int j = 1; j < M-1; j++) {
				ll sum = dp[0][i][j-1] + dp[1][i-1][j] + dp[2][i][j+1] + dp[3][i+1][j];
				ll sum1 = dp[0][i-1][j] + dp[1][i][j+1] + dp[2][i+1][j] + dp[3][i][j-1];
				ans = std::max({ans, sum, sum1});
			}
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}

/*

*/