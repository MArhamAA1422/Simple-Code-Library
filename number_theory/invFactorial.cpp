// BISMILLAH

#include <bits/stdc++.h>

using ll = long long int;

const int MOD = 998244353;
const int mxN = 200005;

int bigmod(int a, int b) {
	if (b==0) return 1;
	ll x = bigmod(a,b/2); ( x *= x ) %= MOD;
	if (b&1) ( x *= a ) %= MOD;
	return (int)x;
}

ll F[mxN], inv_F[mxN];

void fact() {
	F[0] = inv_F[0] = 1;
	for (int i = 1; i < mxN; i++) {
		F[i] = (F[i-1]*i)%MOD;
	}
	inv_F[mxN-1] = bigmod(F[mxN-1],MOD-2);
	for (int i = mxN-2; i >= 0; i--) {
		inv_F[i] = inv_F[i+1]*(i+1)%MOD;
	}
}

signed main() {
	//
	
	return 0;
}

/**

inv(n!)
1/n! = 1/n*(n-1)!
n/n! = n/n*(n-1)!
n/n! = inv(n-1)

*/