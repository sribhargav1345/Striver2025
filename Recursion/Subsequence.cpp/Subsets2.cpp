// If u write a loop in solve function, there is no base condition of idx == n

class Solution {
public:
    void solve(int idx,vector<int>& nums,vector<int>& v,vector<vector<int>>& ans,int n){
        ans.push_back(v);

        for(int i=idx;i<n;i++)
        {
            if(i>idx && nums[i] == nums[i-1]) continue;

            v.push_back(nums[i]);
            solve(i+1,nums,v,ans,n);
            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        vector<int> v;

        solve(0,nums,v,ans,n);

        return ans;
    }
};