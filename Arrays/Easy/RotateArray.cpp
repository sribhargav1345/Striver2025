// Optimal, u did it on your own
class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k = k%n;
        
        vector<int> temp(k,0);

        for(int i=0;i<k;i++)
        {
            temp[i] = arr[i+n-k];
        }

        for(int i=n-1;i>=k;i--)
        {
            arr[i] = arr[i-k];
        }

        for(int i=0;i<k;i++) arr[i] = temp[i];
    }
};