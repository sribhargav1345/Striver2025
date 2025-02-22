class Solution {
    public:
      int totalElements(vector<int> &arr) {
          // code here
          int n = arr.size();
          map<int,int> mp;
          
          int i = 0,j = 0;
          int maxi = 0;
          while(j<n)
          {
              mp[arr[j]]++;
              
              if(mp.size()>2)
              {
                  while(mp.size()>2)
                  {
                      mp[arr[i]]--;
                      if(mp[arr[i]] == 0) mp.erase(arr[i]);
                      i++;
                  }
              }
              
              maxi = max(maxi,j-i+1);
              j++;
          }
          return maxi;
      }
  };