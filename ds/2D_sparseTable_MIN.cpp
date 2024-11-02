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
        int n;
        scanf("%d",&n);
        int m;
        scanf("%d",&m);
        int a[n][m];
        for (int i = 0; i < n; i++) for (int j = 0; j < m; ++j) {
            scanf("%d",&a[i][j]);
        }
        
        ///
        int lim_n = log2(n), lim_m = log2(m);
        int table[n][lim_n + 1][m][lim_m + 1];
        
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                table[r][0][c][0] = a[r][c];
            }
            for (int ci = 1; ci <= lim_m; ci++) {
                for (int c = 0; c+(1<<(ci-1)) < m; c++) {
                    table[r][0][c][ci] = std::min(table[r][0][c][ci-1], table[r][0][c+(1<<(ci-1))][ci-1]);
                }
            }
            // printf("ROW %d\n", r);
            // for (int c = 0; c < m; c++) {
            //     printf("%d: ", c);
            //     for (int ci = 0; ci <= lim_m; ci++) {
            //         printf("%d, ", table[r][0][c][ci]);
            //     }
            //     new_line;
            // }
            // new_line;
        }
        
        for (int ri = 1; ri <= lim_n; ri++) {
            for (int r = 0; r+(1<<(ri-1)) < n; r++) {
                for (int ci = 0; ci <= lim_m; ci++) {
                    for (int c = 0; c < m; c++) {
                        table[r][ri][c][ci] = std::min(table[r][ri-1][c][ci], table[r+(1<<(ri-1))][ri-1][c][ci]);
                    }
                }
            }
        }
        ///
        
        int ans = 0, lo = 1, hi = n, mi;
        while (lo <= hi) {
            mi = lo+(hi-lo)/2;
            bool ok = 0;
            for (int i = 0; i+mi <= n; i++) for (int j = 0; j+mi <= m; j++) {
                int x1 = i, x2 = i+mi-1, y1 = j, y2 = j+mi-1;
                int kx = log2(x2 - x1 + 1);
                int ky = log2(y2 - y1 + 1);
                
                int min_R1 = std::min(table[x1][kx][y1][ky], table[x1][kx][y2 - (1<<ky) + 1][ky]);
                int min_R2 = std::min(table[x2 - (1<<kx) + 1][kx][y1][ky], table[x2 - (1<<kx) + 1][kx][y2 - (1<<ky) + 1][ky]);
                
                int cur_min = std::min(min_R1, min_R2);
                // printf("%d %d : %d %d = %d\n", x1, y1, x2, y2, cur_min);
                
                if (cur_min >= mi) {
                    ok = 1;
                }
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

    NOT TESTED

*/