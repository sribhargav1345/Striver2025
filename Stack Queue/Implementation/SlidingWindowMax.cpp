class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;

        vector<int> ans(n-k+1,0);
        int i=0,j = 0;

        while(j<n)
        {            
            while(!dq.empty() && nums[dq.back()]<nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);

            if(j-i+1 == k){
                ans[i] = nums[dq.front()];
                if(!dq.empty() && dq.front() == i){
                    dq.pop_front();
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};