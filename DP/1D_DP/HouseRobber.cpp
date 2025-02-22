#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);

        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        dp[1] = nums[0];
        for(int i=2;i<n;i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]);
        }

        int k = dp[n-1];

        vector<int> dp2(n+1,0);
        dp2[1] = 0;
        dp2[2] = nums[1];
        for(int i=3;i<=n;i++)
        {
            dp2[i] = max(dp2[i-1],dp2[i-2]+nums[i-1]);
        }

        if(dp2[n]>k) k = dp2[n];

        return k;
    }
};