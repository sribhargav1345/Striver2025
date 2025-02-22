class Solution {
public:
    bool isPali(string s){
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i] != s[n-i-1]) return false;
        }
        return true;
    }

    void solve(int idx,int n,string& s,vector<vector<string>>& ans,vector<string>& v){
        if(idx == n){
            ans.push_back(v);
            return;
        }

        for(int i=idx;i<n;i++)
        {
            string p = s.substr(idx,i-idx+1);
            if(isPali(p)){
                v.push_back(p);
                solve(i+1,n,s,ans,v);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<vector<string>> ans;
        vector<string> v;

        solve(0,n,s,ans,v);
        return ans;
    }
};