class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i=0;i<n;i++)
        {
            sum += nums[i];
        }

        int op = (n+1)*n/2;
        return (op-sum);
    }

};