class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, res = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            res = max(res, pre);
        }
        return res;

    }
};