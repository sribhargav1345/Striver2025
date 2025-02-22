class Solution {
public:
    int histogram(vector<int>& heights) {
        
        // Concept of next smaller and left smaller
        // The answer will be max(rightsmall-leftsmall *a[i]);
        int n = heights.size();

        vector<int> leftsmall(n);
        vector<int> rightsmall(n);

        stack<int> st;

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }

            if(st.empty()) 
            {
                leftsmall[i] = 0;   
                st.push(i); 
            }
            else
            {
                leftsmall[i] = st.top() + 1;
                st.push(i);
            }
        }

        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();          
            }

            if(st.empty()) {
                rightsmall[i] = n-1;
                st.push(i);
            }
            else
            {
                rightsmall[i] = st.top()-1;   
                st.push(i);
            }
        }

        // for(auto x:rightsmall)
        // {
        //     cout<<x<<endl;
        // }

        int maxi = 0;
        for(int i=0;i<n;i++) 
        {
            maxi = max(maxi, heights[i]*(rightsmall[i]-leftsmall[i]+1));
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> arr(m);
        for(int i=0;i<m;i++)
        {
            arr[i] = 0;
        }

        int maxi = 0;

        for(int i=0;i<n;i++)
        {
            vector<char> op = matrix[i];
            for(int i=0;i<m;i++)
            {
                if(op[i]=='1')
                {
                    arr[i] += 1;
                }
                else arr[i] = 0;
            }

            maxi = max(maxi, histogram(arr));
        }
        return maxi;
    }
};