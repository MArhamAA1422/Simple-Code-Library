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
	scanf("%lld",&testCases);
	// std::cin >> testCases;
	
	for (int T = 1; T <= testCases; T++) {
		std::string text;
		std::cin >> text;
		std::string s;
		std::cin >> s;

		int req = (int)s.size();
		s = s + "#" + text;

		int N = (int)s.size();
		int z[N], l = 1;
		z[0] = N;
		z[1] = 0;

		for (int i = 0; i < N-1; i++) {
			if (s[i] != s[i+1])
				break;
			z[1]++;
		}

		for (int i = 2, k; i < N; i++) {
			k = std::min(z[i - l], z[l] + l - i);
			k = std::max(k, 0);
			while (s[k] == s[k+i]) {
				k++;
			}
			z[i] = k;
			if (i+k > l+z[l]) {
				l = i;
			}
		}

		for (int i = 0; i < N; i++) printf("%d ", z[i]); bl;

		bool found = 0;
		for (int i = 0; i < N; i++) {
			if (z[i] == req)
				found = 1;
		}

		printf("%s\n", found ? "YES" : "NO");
	}
	
	return 0;
}

/*
	Z-algo:
		maintain a Z array: max substring that also is a prefix

	FROM: Pavel Mavrin A&DS playlist

*/