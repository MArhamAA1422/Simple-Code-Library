// BISMILLAH

#include "bits/stdc++.h"

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define fastIO std::ios::sync_with_stdio(0);std::cin.tie(0)
#define ll long long int
#define bl printf("\n")

using pii = std::pair<int,int>;

// HASHING
const int BASE [] = {1231, 1567};
const int MOD [] = {1000000000+7, 1000000000+9};

ll b_pow[100100][2];

void calc_b_pow(int n) {
	ll B[2];
	B[0] = B[1] = 1;
	b_pow[0][0] = b_pow[0][1] = 1;
	for (int i = n-1; i >= 0; i--) {
		B[0] *= BASE[0]; B[0] %= MOD[0];
		B[1] *= BASE[1]; B[1] %= MOD[1];
		b_pow[n-i][0] = B[0];
		b_pow[n-i][1] = B[1];
	}
}

pii hash(std::string s, int n) {
	ll fi, se;
	fi = se = 0;
	for (int i = n-1; i >= 0; i--) {
		fi += s[i]*b_pow[n-i-1][0]%MOD[0]; fi %= MOD[0];
		se += s[i]*b_pow[n-i-1][1]%MOD[1]; se %= MOD[1];
	}
	
	return pii((int)fi, (int)se);
}

signed main() {
	// fastIO;
	int testCases=1;
	// scanf("%d",&testCases);
	// std::cin>>testCases;
	
	
	for (int TC = 1; TC <= testCases; TC++) {
		std::string text;
		std::cin >> text;
		
		std::string pat;
		std::cin >> pat;
		int len = (int)pat.size();
		
		if (len > (int)text.size()) {
			puts("NO");
			continue;
		}
		
		calc_b_pow(len);
		auto pattern_hash = hash(pat, len);
		
		std::vector<pii> H((int)text.size());
		H[0] = hash(text.substr(0, len), len);
		
		for (int i = 1; i+len <= (int)text.size(); i++) {
			ll fi = H[i-1].first - (ll)text[i-1] * b_pow[len-1][0]%MOD[0];
			( fi += MOD[0] ) %= MOD[0];
			fi *= BASE[0]; fi %= MOD[0];
			fi += text[i+len-1]; fi %= MOD[0];
			
			ll se = H[i-1].second - (ll)text[i-1] * b_pow[len-1][1]%MOD[1];
			( se += MOD[1] ) %= MOD[1];
			se *= BASE[1]; se %= MOD[1];
			se += text[i+len-1]; se %= MOD[1];
			
			H[i] = pii((int)fi, (int)se);
		}
		
		bool found = 0;
		for (int i = 0; i+len <= (int)text.size(); i++) {
			if (H[i] == pattern_hash) found = 1;
		}
		
		printf("%s\n", found ? "YES":"NO");
		
	}
	
	return 0;
}

/*

	H[i] = hash(substr(i...i+m-1))  // m length substring
	NOT TESTED

*/