// BISMILLAH

#include "bits/stdc++.h"

#define ll long long int

int N, M;
ll dp[12][12][1<<13];

// either keep open the current cell for future or fill it now
ll fn(int i, int j, int profile) {
	if (i == N) {
        if (profile == (1<<M)-1) return 1;
        return 0;
    }
    if (j == M) return fn(i+1, 0, profile);
	if (dp[i][j][profile] != -1) return dp[i][j][profile];
	ll ans = 0;
	if (i == 0) {
        ans += fn(i, j+1, profile>>1);
		if (j) {
            if ((profile&(1<<(M-1))) == 0) {
                ans += fn(i, j+1, (profile>>1)|(1<<(M-1))|(1<<(M-2)));
            }
		}
	} else {
        if ((profile&1) == 0) {
            ans += fn(i, j+1, (profile>>1) | (1<<(M-1)));
        } else {
            ans += fn(i, j+1, profile>>1);
            if (j) {
                if ((profile&(1<<(M-1))) == 0) {
                    ans += fn(i, j+1, (profile>>1)|(1<<(M-1))|(1<<(M-2)));
                }
            }
        }
    }
    return dp[i][j][profile] = ans;
}

signed main() {
	int testCases=1;
	scanf("%d",&testCases);
	
	for (int T = 1; T <= testCases; T++) {
		scanf("%d%d",&N, &M);
		memset(dp, -1, sizeof dp);
		printf("%lld\n", fn(0,0,0));
	}
	
	return 0;
}

/*

	TESTED on: AlgoZenith
	Problem: count # of tiling of a N*M board with 1*2, 2*1 domino
	BitmaskDP

*/