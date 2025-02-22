#include<bits/stdc++.h>
using namespace std;

// Brute force using Map
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mp;
        for(auto x:nums){
            mp[x]++;
        }

        int i = 0;
        for(auto x:mp)
        {
            nums[i] = x.first;
            i++;
        }
        return mp.size();
    }
};

// Optimal using two pointers
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        for(int j=0;j<n;j++)
        {
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};