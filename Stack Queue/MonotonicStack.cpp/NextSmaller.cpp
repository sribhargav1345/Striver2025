#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> Solution::prevSmaller(vector<int> &arr) {
    int n = arr.size();
    stack<int> st;
    
    vector<int> ans;
    ans.push_back(-1);
    st.push(arr[0]);
    
    for(int i=1;i<n;i++)
    {
        while(!st.empty() && st.top()>=arr[i])
        {
            st.pop();
        }
        if(st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        
        st.push(arr[i]);
    }
    
    return ans;
}
