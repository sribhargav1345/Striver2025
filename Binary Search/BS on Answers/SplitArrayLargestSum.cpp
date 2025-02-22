class Solution {
    public:
        int solve(vector<int>& nums,int mid,int k){
            int n = nums.size();
            int ct = 1;
            int sum = 0;
    
            for(int i=0;i<n;i++)
            {
                if(sum + nums[i] > mid){
                    sum = nums[i];
                    ct++;
                }
                else sum += nums[i];
            }
            return (ct <= k);
        }
    
        int splitArray(vector<int>& nums, int k) {
            int n = nums.size();
            int low = *max_element(nums.begin(),nums.end());
            int high = accumulate(nums.begin(),nums.end(),0);
    
            while(low<=high)
            {
                int mid = (low+high)/2;
    
                if(solve(nums,mid,k)) high = mid-1;
                else low = mid + 1;
            }
            return low;
        }
    };