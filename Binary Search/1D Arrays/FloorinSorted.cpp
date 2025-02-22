class Solution {
  public:

    int findFloor(vector<int>& arr, int k) {
        int n = arr.size();
        int op = upper_bound(arr.begin(),arr.end(),k) - arr.begin();
        op--;
        
        if(op == -1 || arr[op]>k) return -1;
        return op;
    }
};

