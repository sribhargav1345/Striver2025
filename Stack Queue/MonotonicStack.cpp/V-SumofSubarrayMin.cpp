// Find the sum of minimum elements of all the subarrays

// Definitely look into it, before interview
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // Problem of monotonic stack
        long long n = arr.size();

        // Our idea... find index of before smallest element,next smallest element... the curent element will be smaller, upto that range...(i-left[i])*(right[i]-i)*arr[i] -> this will be the range upto which it will contribute

        vector<long long> left(n,-1);      // To find previous smaller element
        vector<long long> right(n,n);     // To find next smaller element

        stack<long long> st;              // To iterate the arr given to find left and right vector indices.

        for(long long i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            
            if(!st.empty()) left[i] = st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(long long i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();

            if(!st.empty()) right[i] = st.top();

            st.push(i);
        }

        long long sum = 0;
        int mod = 1e9 + 7;

        for(int i=0;i<n;i++)
        {
            sum += (i-left[i])*(right[i]-i)*arr[i];
            sum %= mod;
        }

        return sum;

    }
};