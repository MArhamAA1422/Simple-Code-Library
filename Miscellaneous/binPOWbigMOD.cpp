// BISMILLAH

#include <bits/stdc++.h>

using ll = long long;

int bigmod(int a, int b, int MOD) {
	if (b==0) return 1;
	ll x = bigmod(a,b/2,MOD); ( x *= x ) %= MOD;
	if (b&1) ( x *= a ) %= MOD;
	return (int)x;
}

ll binpow(ll a, ll b) {
	if (b==0) return 1;
	ll x = binpow(a,b/2); x *= x;
	if (b&1) x *= a;
	return x;
}

signed main() {
	// do stuffs
	
	return 0;
}

/**

	simple & basic

*/