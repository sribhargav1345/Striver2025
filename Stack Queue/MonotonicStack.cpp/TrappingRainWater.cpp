// Ideally, we are doing for every index, min(maxLeft,maxRight) - that element

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int left = 0;
        int right = n-1;

        int maxl = 0,maxr= 0;
        int ans = 0;
        while(left<=right)
        {
            if(height[left]<=height[right]){
                if(height[left]>=maxl){
                    maxl = height[left];
                }
                else ans += (maxl-height[left]);
                left++;
            }
            else
            {
                if(height[right]>=maxr){
                    maxr = height[right];
                }
                else ans += (maxr-height[right]);
                right--;
            }
        }
        return ans;
    }
};