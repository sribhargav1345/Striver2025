class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j = 1;

        while(j<n)
        {
            if(nums[j]==0 && nums[i]==0){
                j++;
            }
            else if(nums[i]==0 && nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else{
                i++;
                j++;
            }
        }
    }
};