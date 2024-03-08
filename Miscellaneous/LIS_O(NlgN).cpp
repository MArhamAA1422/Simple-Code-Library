// BISMILLAH

// Problem link: https://leetcode.com/problems/longest-increasing-subsequence/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> ans;
        for (auto i : nums) {
            auto it = lower_bound(ans.begin(), ans.end(), i);
            if (it == ans.end()) ans.push_back(i);
            else {
                int at = it-ans.begin();
                ans[at] = i;
            }
        }
        return (int)ans.size();
    }
};

signed main() {
    //
}

/*

"If the number is greater than the last 
element append cur to the end of the list. 
Otherwise, find the smallest element that 
is greater than or equal to the cur. 
Replace that with cur."

"O(N lg N)
from GFG"

*/