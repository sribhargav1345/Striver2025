class Solution {
public:
    void solve(vector<string>& v,string s,int open,int close,int n){
        if(close == n){
            v.push_back(s);
            return;
        }

        if(open == close){
            solve(v,s + '(',open+1,close,n);
        }        
        else if(open == n){
            solve(v,s+')',open,close+1,n);
        }
        else
        {
            solve(v,s+'(',open+1,close,n);
            solve(v,s+')',open,close+1,n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> v;

        string ans = "";

        solve(v,ans,0,0,n);       // ct for count of parenthesis

        return v;
    }
};