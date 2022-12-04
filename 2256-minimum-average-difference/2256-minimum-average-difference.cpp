class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long leftsum = 0, rightsum = 0;
        for(long long num : nums) rightsum += num;
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