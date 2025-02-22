class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int n = nums.size();
            
            int i=0,j=0;
            int op = 0;
            int maxi = 0;
    
            while(j<n)
            {
                if(nums[j] == 0){
                    op++;
                    while(i<=j && op>k){
                        if(nums[i] == 0) op--;
                        i++;
                    }
                }
                maxi = max(maxi,j-i+1);
                j++;
            }
            return maxi;
        }
    };