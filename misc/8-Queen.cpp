// BISMILLAH

#include "bits/stdc++.h"

#define fastIO std::ios::sync_with_stdio(0);std::cin.tie(0)
#define ll long long int
#define flush fflush(stdout)
// #define int ll

using pii = std::pair<int,int>;

const int MOD = 1000000007;
// const int MOD = 998244353;
const int mxN = 500005, inf = 1000000005;

char g[8][8];
int N = 8;

int fn(int row, int col, int dig1, int dig2) {
    if (row == 8) return 1;
    int ans = 0;
    for (int i = 0; i < 8; i++) {
        if (g[row][i] == '.') {
            if (col&(1<<i)) continue;
            int mn = std::min(row, i);
            int R = row-mn;
            int C = i-mn;
            int L, RR;
            if (R == 0) {
                L = N - C - 1;
            } else {
                L = N + R - 1;
            }
            if (dig1&(1<<L)) continue;
            mn = std::min(row, N-i-1);
            R = row - mn;
            C = i + mn;
            if (R == 0) {
                RR = C;
            } else {
                RR = N + R - 1;
            }
            if (dig2&(1<<RR)) continue;
            ans += fn(row+1, col | (1<<i), dig1 | (1<<L), dig2 | (1<<RR));
        }
    }
    return ans;
}

signed main() {
    // fastIO;
    int testCases=1;
    // scanf("%lld",&testCases);
    // std::cin >> testCases;
	
    for (int T = 1; T <= testCases; T++) {
        for (int i = 0; i < 8; i++) {
           scanf(" ");
           for (int j = 0; j < 8; j++) scanf("%c",&g[i][j]);
        }
        printf("%d", fn(0,0,0,0));
    }
	
    return 0;
}

/*

*/