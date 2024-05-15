// BISMILLAH

#include "bits/stdc++.h"

#define fastIO std::ios::sync_with_stdio(0);std::cin.tie(0)
#define ll long long int

const int mxN = 500005, inf = 1000000005;

int ST[mxN][21], ST1[mxN][21];

int lim(int x) {
	int ans;
	for (int i = 20; i >= 0; i--) {
		if ((1<<i) <= x) {
			ans = i;
			break;
		}
	}
	return ans;
}

int MIN(int l, int r) {
	int m = lim(r-l+1);
	return std::min(ST[l][m], ST[r-(1<<m)+1][m]);
}

int MAX(int l, int r) {
	int m = lim(r-l+1);
	return std::max(ST1[l][m], ST1[r-(1<<m)+1][m]);
}

signed main() {
	// fastIO;
	int testCases=1;
	scanf("%lld",&testCases);
	// std::cin >> testCases;
	
	for (int T = 1; T <= testCases; T++) {
        int N;
        scanf("%d", &N);
        int a[N];
        for (int &i : a) {
            scanf("%d", &i);
        }
        for (int i = 1; i <= N; i++) {
            ST[i][0] = ST1[i][0] = a[i];
        }
        for (int j = 1; j <= 20; j++) {
            for (int i = 1; i+(1<<(j))-1 <= N; i++) {
                ST[i][j] = std::min(ST[i][j-1], ST[i+(1<<(j-1))][j-1]);
                ST1[i][j] = std::max(ST1[i][j-1], ST1[i+(1<<(j-1))][j-1]);
            }
        }
    }
	
	return 0;
}

/*

1-based indexing
TESTED on- AtCoder

*/