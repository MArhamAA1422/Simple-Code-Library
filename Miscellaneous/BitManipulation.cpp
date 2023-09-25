// BISMILLAH

#include <bits/stdc++.h>

using ll = long long;

int isOn(int x, int k) { // k is zero based here
	return x&(1<<k);
}

int isOff(int x, int k) {
	return !isOn(x,k);
}

int doOn(int x, int k) {
	return x|(1<<k);
}

int doOff(int x, int k) { // also we can think of doing AND operation
	if (isOn(x,k)) {
		x ^= (1<<k);
	}
	return x;
}

int isPowerOfTwo(int x) {
	return !(x&(x-1));
}

int toggleBit(int x, int k) {
	return x^(1<<k);
}

int modByPowerOfTwo(int x, int k) { // x % 2^k
	return x&( (1<<k)- 1 );
}

int removeLastSetBit(int x) {
	return x&(x-1);
}

int numOfSetBits(int x) {
	return __builtin_popcount(x);
}

ll isOn(ll x, int k) { // k is zero based here
	return x&(1ll<<k);
}

ll isOff(ll x, int k) {
	return !isOn(x,k);
}

ll doOn(ll x, int k) {
	return x|(1ll<<k);
}

ll doOff(ll x, int k) { // also we can think of doing AND operation
	if (isOn(x,k)) {
		x ^= (1ll<<k);
	}
	return x;
}

ll isPowerOfTwo(ll x) {
	return !(x&(x-1));
}

ll toggleBit(ll x, int k) {
	return x^(1ll<<k);
}

ll modByPowerOfTwo(ll x, int k) { // x % 2^k
	return x&( (1ll<<k)- 1 );
}

ll removeLastSetBit(ll x) {
	return x&(x-1);
}

int numOfSetBits(ll x) {
	return __builtin_popcountll(x);
}

signed main() {
	int x;
	ll y;
	
	// do other stuffs
	
	return 0;
}