class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> table(nums.size());
        table[0] = nums.front();
        for(int i = 1; i < nums.size(); i++){
            table[i] = max(table[i - 1], 0) + nums[i];
        }
        return *max_element(table.begin(), table.end());
    }
};