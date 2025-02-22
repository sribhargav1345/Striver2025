class Solution {
    public:
      int findKRotation(vector<int> &arr) {
          // Code Here
          int n = arr.size();
          int low = 0;
          int high = n-1;
          
          int ans = INT_MAX;
          int k = -1;
  
          while(low<=high)
          {
              int mid = (low+high)/2;
              
              if(arr[low]<=arr[high]){
                  return low;
              }
              else if(arr[low]<=arr[mid]){
                  low = mid + 1;
              }
              else
              {
                  high = mid;
              }
          }
          return k;
      }
  };