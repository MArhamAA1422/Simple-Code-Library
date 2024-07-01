// BISMILLAH

#include "bits/stdc++.h"

#define fastIO std::ios::sync_with_stdio(0);std::cin.tie(0)
#define ll long long int
#define bl printf("\n")

const int MOD = 1000000007;
// const int MOD = 998244353;
const int mxN = 500005, inf = INT_MAX;

struct monotone_deq {
	std::deque<ll> dq;
	void insert(ll v) {
		while ((int)dq.size() && dq.back() > v) {
			dq.pop_back();
		}
		dq.push_back(v);
	}
	void remove(ll v) {
		if ((int)dq.size() && dq.front() == v) {
			dq.pop_front();
		}
	}
	ll getMin() {
		if ((int)dq.size()) return dq.front();
		return 0;
	}
};

signed main() {
	// fastIO;
	int testCases=1;
	scanf("%d",&testCases);
	// std::cin >> testCases;
	
	for (int T = 1; T <= testCases; T++) {
		int N, k;
		scanf("%d%d",&N, &k);
		monotone_deq window;
		int a[N];
		
		for (int i = 0,x; i < N; i++) {
			scanf("%d",&x);
			a[i] = x;
			window.insert(x);
			if (i-k >= 0) window.remove(a[i-k]);
			
			printf("%d ", window.getMin());
		}
		bl;
		
	}
	
	return 0;
}

/*

	TESTED on- AlgoZenith

*/