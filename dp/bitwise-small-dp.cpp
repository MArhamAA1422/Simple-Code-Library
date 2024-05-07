// BISMILLAH

#include "bits/stdc++.h"

#define fastIO std::ios::sync_with_stdio(0);std::cin.tie(0)
#define ll long long int
#define flush fflush(stdout)
// #define int ll

using pii = std::pair<int,int>;

const int MOD = 1000000007;
// const int MOD = 998244353;
const int mxN = 200005, inf = 1000000005, bit_len = 60;

int N;
ll k;
int bit[bit_len];

ll dp[bit_len][2];

ll fn(int b, bool small) {
    if (b == -1) return 0;
    if (dp[b][small] != -1) return dp[b][small];
    ll ans = 0;
    if (small) {
        ans = (1ll << b)*std::max(bit[b], N - bit[b]) + fn(b-1, 1);
    } else {
        if ((1ll<<b)&k) {
            ll ans1 = (1ll << b) * bit[b] + fn(b - 1, 1);
            ll ans2 = (1ll << b) * (N - bit[b]) + fn(b - 1, 0);
            ans = std::max(ans1, ans2);
        } else {
            ans = (1ll << b) * bit[b] + fn(b-1, 0);
        }
    }
    return dp[b][small] = ans;
}

signed main() {
    // fastIO;
	int testCases=1;
	// scanf("%lld",&testCases);

    for (int T = 1; T <= testCases; T++) {
        scanf("%d%lld", &N, &k);
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < N; i++) {
            ll a;
            scanf("%lld", &a);
            for (int b = 0; b < bit_len; b++) {
                if ((1ll<<b)&a) {
                    bit[b]++;
                }
            }
        }
        int st_bit;
        for (int i = bit_len - 1; i >= 0; i--) {
            if ((1ll<<i)&k) {
                st_bit = i;
                break;
            }
        }
        ll ans = 0;
        for (int i = bit_len - 1; i > st_bit; i--) {
            ans += (1ll << i) * bit[i];
        }
        printf("%lld\n", ans+fn(st_bit, 0));
    }
	
	return 0;
}

/*

TESTED on: SeriousOJ

*/