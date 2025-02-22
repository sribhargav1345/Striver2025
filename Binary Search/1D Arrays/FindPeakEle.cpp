class Solution {
    public:
        int findPeakElement(vector<int>& arr) {
            int n = arr.size();
            if(n == 1) return 0;
            
            if(arr[1]<arr[0]) return 0;
            if(arr[n-2]<arr[n-1]) return n-1;
    
            int low = 0,high = n-1;
            while(low <= high)
            {
                int mid = (low+high)/2;
                if(arr[mid]>arr[mid-1] && arr[mid+1]<arr[mid]){
                    return mid;
                }
                if(arr[mid] > arr[mid+1]){
                    high = mid;
                }
                else low = mid + 1;
            }
            return -1;
        }
    };