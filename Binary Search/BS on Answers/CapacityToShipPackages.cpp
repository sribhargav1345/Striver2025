class Solution {
    public:
        int solve(int mid,vector<int>& weights,int days){
            int n = weights.size();
            int ct = 1;
            int sum = 0;
    
            for(int i=0;i<n;i++)
            {
                if(sum + weights[i] > mid){
                    ct++;
                    sum = weights[i];
                }
                else sum += weights[i];
            }
            return (ct<=days);
        }
        int shipWithinDays(vector<int>& weights, int days) {
            int n = weights.size();
            int low = *max_element(weights.begin(),weights.end());
            int high = accumulate(weights.begin(),weights.end(),0);
    
            while(low <= high)
            {
                int mid = (low+high)/2;
                if(solve(mid,weights,days)) high = mid - 1;
                else low = mid + 1;
            }
            return low;
        }
    };