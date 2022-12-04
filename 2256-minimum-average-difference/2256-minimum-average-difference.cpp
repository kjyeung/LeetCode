class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long rightsum = accumulate(nums.begin(), nums.end(), (long long)0);
        long long leftsum = 0;
        int ret = 0;
        long long mad = rightsum;
        int n = nums.size();
        for(long long i = 0; i < nums.size();i++){
            leftsum += (long long)nums[i];
            rightsum -= (long long)nums[i];
            long long tmp;
            if(i < n - 1){
                tmp = llabs(leftsum / (i+1) - rightsum/(n - i - 1));
            }else tmp = leftsum / (i + 1);
            if(tmp < mad){
                mad = tmp;
                ret = i;
            }
        }
        return ret;
        
        
    }
};