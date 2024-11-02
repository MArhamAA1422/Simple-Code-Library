// I AM A MUSLIM

#include "bits/stdc++.h"

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define fast_io std::ios::sync_with_stdio(0);std::cin.tie(0)
#define lli long long int
#define flush fflush(stdout)
#define new_line printf("\n")
#define yn(a, b) printf("%s\n", a >= b ? "Yes":"No")
#define safe_mod(a, M) ((a%M+M)%M)
// #define int lli

using pii = std::pair<int,int>;

const int MOD = 1000000007;
const int mxN = 100100;

signed main() {
    int testCases=1;
    scanf("%d",&testCases);
    
    for (int TC = 1; TC <= testCases; TC++) {
        int n; scanf("%d",&n);
        int m; scanf("%d",&m);
        
        int a[n][m];
        int st[n][m][15];
        
        for (int i = 0; i < n; i++) for (int j = 0; j < m; ++j) {
            scanf("%d",&a[i][j]);
            st[i][j][0] = a[i][j];
        }
        
        ///
        for (int k = 1; k <= log2(std::min(n,m)); k++) {
            for (int i = 0; i+(1<<k) <= n; i++) {
                for (int j = 0; j+(1<<k) <= m; j++) {
                    st[i][j][k] = std::min({st[i][j][k-1], st[i+(1<<(k-1))][j][k-1], st[i][j+(1<<(k-1))][k-1], st[i+(1<<(k-1))][j+(1<<(k-1))][k-1]});
                }
            }
        }
        ///
        
        int ans = 0, lo = 1, hi = n, mi;
        while (lo <= hi) {
            mi = lo+(hi-lo)/2;
            int k = log2(mi);
            bool ok = 0;
            
            for (int i = 0; i+mi <= n; i++) for (int j = 0; j+mi <= m; j++) {
                int x1 = i, x2 = i+mi-1, y1 = j, y2 = j+mi-1;
                int val = std::min({st[x1][y1][k], st[x1][y2-(1<<k)+1][k], st[x2-(1<<k)+1][y1][k], st[x2-(1<<k)+1][y2-(1<<k)+1][k]});
                if (val >= mi) ok = 1;
            }
            
            if (ok) {
                ans = mi;
                lo = mi+1;
            } else hi = mi-1;
        }
        
        printf("%d\n", ans);
        
    }
    
    return 0;
}

/*

	TESTED on CODEFORCES

*/