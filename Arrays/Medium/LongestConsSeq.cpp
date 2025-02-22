class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }

        unordered_set<int> st;
        for(auto x:nums){
            st.insert(x);
        }

        int maxi = 0;
        for(auto it:st){
            // checking if it's the first elem
            if(st.find(it-1) != st.end()) continue;

            int x = it;
            int cnt = 1;
            while(st.find(x+1) != st.end())
            {
                cnt++;
                x++;
            }
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};