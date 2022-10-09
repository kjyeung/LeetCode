class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp0 = nums.front();
        int dp1 = 0, res = dp0;
        for(int i = 1; i < nums.size(); i++){
            dp1 = max(0, dp0) + nums[i];
            dp0 = dp1;
            res = max(dp1, res);
        }
        return res;
    }
};