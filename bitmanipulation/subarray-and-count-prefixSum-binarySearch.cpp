// BISMILLAH

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int N = (int)nums.size();
        int pre[N+1][31];
        for (int i = 0; i < 31; i++) pre[0][i] = 0;
        for (int i = 1; i <= N; i++) {
            int v = nums[i-1];
            for (int b = 0; b < 31; b++) {
                pre[i][b] = pre[i-1][b];
                if ((1<<b)&v) pre[i][b]++;
            }
        }

        long long ans = 0;
        for (int i = 1; i <= N; i++) {
            int lo = i, hi = N, mi, j_first = -1;
            while (lo <= hi) {
                mi = lo+(hi-lo)/2;
                int val = 0;
                for (int b = 0; b < 31; b++) {
                    int tot = pre[mi][b] - pre[i-1][b];
                    if (tot == mi-i+1) val |= (1<<b);
                }
                if (val == k) {
                    j_first = mi;
                    hi = mi-1;
                } else if (val < k) {
                    hi = mi-1;
                } else {
                    lo = mi+1;
                }
            }
            // printf("%d: ",i);
            // printf("j_first: %d, ", j_first);
            if (j_first != -1) {
                lo = j_first, hi = N;
                int j_last = j_first;
                while (lo <= hi) {
                    mi = lo+(hi-lo)/2;
                    int val = 0;
                    for (int b = 0; b < 31; b++) {
                        int tot = pre[mi][b] - pre[i-1][b];
                        if (tot == mi-i+1) val |= (1<<b);
                    }
                    if (val == k) {
                        j_last = mi;
                        lo = mi+1;
                    } else if (val < k) {
                        hi = mi-1;
                    } else {
                        lo = mi+1;
                    }
                }
                ans += j_last-j_first+1;
            }
        }
        return ans;
    }
};

signed main() {
	//
}

/*

	TESTED on: LEETCODE

*/