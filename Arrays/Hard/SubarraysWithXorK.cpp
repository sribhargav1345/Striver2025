int Solution::solve(vector<int> &a, int k) {
    int n = a.size();
    map<int,int> mp;
    
    mp[0] = 1;
    int xo = 0;
    int ans = 0;
    
    for(int i=0;i<n;i++)
    {
        xo ^= a[i];
        if(mp.find(xo^k) != mp.end()){
            ans += mp[xo^k];
        }
        mp[xo]++;
    }
    return ans;
}
