class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        
        int lb = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int ub = upper_bound(nums.begin(),nums.end(),target) - nums.begin();

        if(lb>=n) return n;  
        if(ub<=0) return 0;

        return (ub-lb+1); 
    }
};