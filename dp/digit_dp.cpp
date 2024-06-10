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

ll dp[20][10][2][2];

ll fn(std::string s, int at, int lst, bool status, bool zero) {
	if (at == (int)s.size()) return 1;
	if (dp[at][lst][status][zero] != -1) return dp[at][lst][status][zero];

	ll ans = 0;
	if (status) {  // already smaller
		if (zero) ans += fn(s, at+1, 0, status, zero);
		else if (lst) ans += fn(s, at+1, 0, status, zero);
		for (int i = 1; i < 10; i++) {
			if (i == lst) continue;
			ans += fn(s, at + 1, i, status, 0);
		}
	} else {
		int lim = s[at] - '0';
		if (at == 0) {
			ans += fn(s, at + 1, lim, status, (lim == 0 ? 1 : 0));
			// printf("here: %lld\n", ans);
			if (lim) ans += fn(s, at+1, 0, 1, 1);
			for (int i = 1; i < lim; i++) {
				ans += fn(s, at + 1, i, 1, 0);
			}
			// printf("then: %lld\n", ans);
		} else {
			if (lst) {
				if (lim) ans += fn(s, at+1, 0, 1, zero);
				// else ans += fn(s, at+1, 0, 0, zero);
			} else {
				if (zero && lim) ans += fn(s, at+1, 0, 1, zero);
			}
			for (int i = 1; i < lim; i++) {
				if (i == lst) continue;
				ans += fn(s, at + 1, i, 1, 0);
			}
			if (lst != lim) ans += fn(s, at + 1, lim, status, zero);
		}
	}

	return dp[at][lst][status][zero] = ans;
}

signed main() {
	// fastIO;
	int testCases=1;
	// scanf("%lld",&testCases);
	// std::cin >> testCases;
	
	for (int T = 1; T <= testCases; T++) {
		ll a, b;
		scanf("%lld %lld", &a, &b);

		memset(dp, -1, sizeof(dp));
		ll R = fn(std::to_string(b), 0, 0, 0, 1);

		memset(dp, -1, sizeof(dp));
		ll L = a ? fn(std::to_string(a-1), 0, 0, 0, 1) : 0;

		// printf("%lld %lld\n", L, R);

		printf("%lld", R - L);
	}
	
	return 0;
}

/*

	TESTED on: CSES

*/