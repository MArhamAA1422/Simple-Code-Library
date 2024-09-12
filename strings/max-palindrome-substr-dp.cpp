// I'm a Muslim

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int N, dp[1010][1010];

bool fn(int l, int r, string& s) {
    if (l >= r) return 1;
    if (dp[l][r] != -1) return dp[l][r];
    if (s[l] != s[r]) return dp[l][r] = 0;
    return dp[l][r] = fn(l+1, r-1, s);
}

int minPalindromeSubstr(string& s) {
    memset(dp, -1, sizeof dp);
    N = (int)s.size();
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            fn(i,j,s);
        }
    }
    int ans = 0;
    for (int len = N; len; len--) {
        for (int i = 0; i+len <= N; i++) {
            if (dp[i][i+len-1]) {
                ans = len;
                break;
            }
        }
        if (ans) break;
    }
    return ans;
}

signed main() {
    string s;
    cin >> s;
    
    return 0;
}
