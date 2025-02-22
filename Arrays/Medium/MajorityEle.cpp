class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore's voting
        int n = nums.size();
        int cnt = 0,ele = INT_MIN;

        for(int i=0;i<n;i++)
        {
            if(cnt == 0){
                ele = nums[i];
                cnt++;
            }
            else if(ele == nums[i]){
                cnt++;
            }
            else cnt--;
        }

        cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == ele) cnt++;
        }
        if(2*cnt>n) return ele;
        else return -1;
    }
};