// remember n-1 C r-1
class Solution {
public:
    int nCi(int n,int i){
        int ans = 1;
        for(int j=0;j<i;j++){
            ans *= (n-j);
            ans /= (j+1);
        }
        return ans;
    }

    void generateRows(int row,vector<int>& v)
    {
        for(int i=1;i<=row;i++){
            v.push_back(nCi(row-1,i-1));
        }
    }

    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> ans;

        for(int i=1;i<=n;i++)
        {
            vector<int> v;
            generateRows(i,v);

            ans.push_back(v);
        }
        return ans;
    }
};