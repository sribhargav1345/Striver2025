#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));

        dp[1][1] = grid[0][0];
        for(int i=2;i<=m;i++)
        {
            dp[1][i] = dp[1][i-1] + grid[0][i-1];
        }

        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i-1][j-1];
            }
        }

        return dp[n][m];
    }
};