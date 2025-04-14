// I AM A MUSLIM

#include "bits/stdc++.h"

#define lli long long int
const int MOD = 1000000007;
const int mxN = 1005;

lli ncr[mxN][mxN];

void combinations() {
    ncr[0][0] = 1;
    for (int i = 1; i < mxN; i++) {
        ncr[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
            ncr[i][j] %= MOD;
        }
    }
}

signed main() {
    int testCases=1;
    // scanf("%d",&testCases);
    
    for (int TC = 1; TC <= testCases; TC++) {
        combinations();
    }
    
    return 0;
}