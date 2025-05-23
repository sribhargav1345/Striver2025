// Different model

class Solution {
    public:
        int solve(vector<int>& nums,int k){
            int n = nums.size();
            int i = 0,j = 0;
    
            map<int,int> mp;
            int ans = 0;
            while(j<n)
            {
                mp[nums[j]]++;
    
                while(mp.size()>k)
                {
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0) mp.erase(nums[i]);
                    i++;
                }
    
                ans += (j-i+1);
                j++;
            }
            return ans;
        }
    
        int subarraysWithKDistinct(vector<int>& nums, int k) {
            return solve(nums,k) - solve(nums,k-1);
        }
    };