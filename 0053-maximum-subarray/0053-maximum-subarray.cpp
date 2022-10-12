class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        int dp1 = nums[0];
        for(int i = 1; i < nums.size(); i++){
            nums[i] = max(nums[i], nums[i - 1] + nums[i]);
            ret = max(ret, nums[i]);
        }
        return ret;
    }
};