class Solution{
public:
    void solve(int idx,string& s,vector<string>& ans,int num){
        if(idx == num){
            ans.push_back(s);
            return;
        }    
        
        if(s.empty() || s.back() != '1'){
            s.push_back('0');
            solve(idx+1,s,ans,num);
            s.pop_back();
            
            s.push_back('1');
            solve(idx+1,s,ans,num);
            s.pop_back();
        }
        else{
            s.push_back('0');
            solve(idx+1,s,ans,num);
            s.pop_back();
        }
    }
    
    vector<string> generateBinaryStrings(int num){
        vector<string> ans;
        string s = "";
        
        solve(0,s,ans,num);
        return ans;
    }
};