// BISMILLAH

#include <bits/stdc++.h>

const int siz = 10000007;
int siv[siz];
std::vector<int> primes;

void sieve() {
	primes.push_back(2);
	
	for (int i = 3; i*i < siz; i += 2) {
		if (siv[i]==0) for (int j = i*i; j < siz; j += 2*i) siv[j] = 1;
	}
	
	for (int i = 3; i < siz; i += 2) {
		if (siv[i]==0) primes.push_back(i);
	}
}

signed main() {
	// do stuffs
	
	return 0;
}

/**

	simlple fast sieve

*/