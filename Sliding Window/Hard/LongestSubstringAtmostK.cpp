class Solution {
    public:
      int longestKSubstr(string &s, int k) {
          int n = s.size();
          int i = 0,j = 0;
          int maxi = -1;
          
          map<int,int> mp;
          
          while(j<n)
          {
              mp[s[j]]++;
              while(mp.size()>k)
              {
                  mp[s[i]]--;
                  if(mp[s[i]]==0) mp.erase(s[i]);
                  
                  i++;
              }
              if(mp.size() == k) maxi = max(maxi,j-i+1);
              j++;
          }
          return maxi;
      }
  };