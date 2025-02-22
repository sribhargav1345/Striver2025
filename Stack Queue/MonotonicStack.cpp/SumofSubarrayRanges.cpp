class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;

        // No. of arrays in which it is largest, No. of arrays in which it is smallest.. do (n-m)*arr[i] for each element
        vector<long long> lefts(n,-1);      // To find previous smaller element
        vector<long long> rights(n,n);     // To find next smaller element

        stack<long long> st;              // To iterate the arr given to find left and right vector indices.

        for(long long i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            
            if(!st.empty()) lefts[i] = st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(long long i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();

            if(!st.empty()) rights[i] = st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        vector<int> leftg(n,-1);
        vector<int> rightg(n,n);

        for(long long i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
            
            if(!st.empty()) leftg[i] = st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(long long i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]<arr[i]) st.pop();

            if(!st.empty()) rightg[i] = st.top();

            st.push(i);
        }

        for(int i=0;i<n;i++)
        {
            ans += ((i-leftg[i])*(rightg[i]-i) - (i-lefts[i])*(rights[i]-i))*arr[i];
        }
        return ans;
    }
};