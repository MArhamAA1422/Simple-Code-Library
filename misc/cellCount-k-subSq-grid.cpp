// I AM A MUSLIM

#include "bits/stdc++.h"

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define fastIO std::ios::sync_with_stdio(0);std::cin.tie(0)
#define ll long long int
#define flush fflush(stdout)
#define bl printf("\n")
#define yn(a, b) printf("%s\n", a >= b ? "Yes":"No")
// #define int ll

using pii = std::pair<int,int>;

const int MOD = 1000000007;
// const int MOD = 998244353;
const int mxN = 100100;

signed main() {
    // fastIO;
    int testCases=1;
    scanf("%d",&testCases);
    // std::cin>>testCases;
    
    for (int TC = 1; TC <= testCases; TC++) {
        int N;
        scanf("%d",&N);
        int M, k; scanf("%d%d",&M,&k);
        
        std::priority_queue<int> pq;
        for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) {
            int rL = std::max(1, i-(k-1)), rR = std::min(N-k+1, i);
            int cL = std::max(1, j-(k-1)), cR = std::min(M-k+1, j);
            // printf("%d %d : (%d,%d), (%d,%d)\n", i,j,rL,rR,cL,cR);
            int row = rR-rL+1; row = std::max(row,0);
            int col = cR-cL+1; col = std::max(col,0);
            if (cL <= cR && rL <= rR) pq.push(row*col);
        }
        
    }
    
    return 0;
}

/*

    TESTED on CF

*/