// BISMILLAH

#include "bits/stdc++.h"

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define fastIO std::ios::sync_with_stdio(0);std::cin.tie(0)
#define ll long long int
#define bl printf("\n")
// #define int ll

const int mxN = 10010, inf = 1000000005;

int N;
int a[mxN];
int dp[mxN], dp1[mxN];

signed main() {
	// fastIO;
	int testCases=1;
	scanf("%d",&testCases);
	// std::cin >> testCases;
	
	for (int T = 1; T <= testCases; T++) {
        scanf("%d",&N);
        for (int i = 0; i < N; i++) scanf("%d",&a[i]);
        if (N < 3) {
            puts("-1");
            continue;
        }
        std::vector<int> lis;
        
        // from left to right
        for (int i = 0; i < N; i++) {
            int x = a[i], ans;
            auto it = lower_bound(lis.begin(), lis.end(), x);
            if (it == lis.end()) {
                lis.push_back(x);
                ans = (int)lis.size();
            } else {
                *it = x;
                ans = it-lis.begin()+1;
            }
            dp[i] = ans;
        }
        lis.clear();
        
        // from right to left
        for (int i = N-1; i >= 0; i--) {
            int x = a[i], ans;
            auto it = lower_bound(lis.begin(), lis.end(), x);
            if (it == lis.end()) {
                lis.push_back(x);
                ans = (int)lis.size();
            } else {
                *it = x;
                ans = it-lis.begin()+1;
            }
            dp1[i] = ans;
        }
        // for (int i = 0; i < N; i++) {
        //     printf("%d %d\n", dp[i], dp1[i]);
        // }
        int ans = 0;
        for (int i = 1; i <= N-2; i++) {
            if (dp[i] == 1 || dp1[i] == 1) continue;
            ans = std::max(ans, dp[i] + dp1[i] - 1);
        }
        
        if (ans < 3) ans = -1;
        else ans = N-ans;
        printf("%d\n", ans);
        
    }
	
	return 0;
}

/*

    TESTED on- AlgoZenith

*/