class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        map<int,int> mp;
        
        mp[0] = -1;
        int sum = 0;
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            if(mp.find(sum-k) != mp.end()){
                ans = max(ans,i-mp[sum-k]);
            }
            
            if(mp.find(sum) == mp.end()) mp[sum] = i;
        }
        return ans;
    }
};