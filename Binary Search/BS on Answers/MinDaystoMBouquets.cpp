class Solution {
    public:
        int f(vector<int>& bloomDay,int mid,int m,int k){
            int n = bloomDay.size();
            int ct = 0;
            int cnt = 0;
            
            for(int i=0;i<n;i++)
            {
                if(bloomDay[i]<=mid){
                    ct++;
                }
                else{
                    ct = 0;
                }
    
                if(ct == k){
                    ct = 0;
                    cnt++;
                }
    
                if(cnt>=m){
                    return true;
                }
            }
            return false;
        }
    
        int minDays(vector<int>& bloomDay, int m, int k) {
            int n = bloomDay.size();
    
            for(int i=1;i<=m;i++){
                if(i*k>n) return -1;
            }
    
            int low = 1;
            int high = *max_element(bloomDay.begin(),bloomDay.end());
    
            while(low<=high)
            {
                int mid = (low+high)/2;
    
                if(f(bloomDay,mid,m,k)){
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            return low;
        }
    };