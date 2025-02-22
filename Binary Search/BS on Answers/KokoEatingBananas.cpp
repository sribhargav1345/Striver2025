class Solution {
    public:
        int solve(int mid,vector<int>& piles,int h){
            int n = piles.size();
            int ct = 0;
            for(int i=0;i<n;i++)
            {
                if(piles[i]%mid>0){
                    ct++;
                }
                ct += (piles[i]/mid);
    
                if(ct>h) return false;
            }
            return true;
        }
    
        int minEatingSpeed(vector<int>& piles, int h) {
            int n = piles.size();
            sort(piles.begin(),piles.end());
    
            int low = 1;
            int high = piles[n-1];
    
            while(low <= high)
            {
                int mid = (low+high)/2;
                if(solve(mid,piles,h)) high = mid - 1;
                else low = mid + 1;
            }
            return low;
        }
    };