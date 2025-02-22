class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                st.push(nums[i]);
            }
            else
            {
                if(st.empty() || st.top()<0) st.push(nums[i]);
                else
                {
                    while(!st.empty() && st.top()>0 && st.top()<abs(nums[i]))
                    {
                        st.pop();
                    }

                    if(st.empty() || st.top()<0) st.push(nums[i]);
                    else
                    {
                        if(st.top() > 0 && st.top() == abs(nums[i])) st.pop();
                        else continue;
                    }
                }
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());  
        return ans;
    }
};