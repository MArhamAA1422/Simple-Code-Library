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

signed main() {
	// fastIO;
	int testCases=1;
	// scanf("%lld",&testCases);
	// std::cin >> testCases;
	
	for (int T = 1; T <= testCases; T++) {
		int a[6], b[6];
		for (auto &i : a) scanf("%d",&i);
		for (auto &i : b) scanf("%d",&i);
		int yes = 0;
		int l, w, h;
		if (a[0] <= b[0]) {
			l = std::min(a[3], b[3]) - b[0];
		} else {
			l = std::min(a[3], b[3]) - a[0];
		}
		if (a[1] <= b[1]) {
			w = std::min(a[4], b[4]) - b[1];
		} else {
			w = std::min(a[4], b[4]) - a[1];
		}
		if (a[2] <= b[2]) {
			h = std::min(a[5], b[5]) - b[2];
		} else {
			h = std::min(a[5], b[5]) - a[2];
		}
		yes = l * w * h;
		printf("%s", yes > 0 ? "Yes" : "No");
	}
	
	return 0;
}

/*

*/