class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i-1] >= 0? nums[i - 1] : 0;
        }
        return *max_element(nums.begin(), nums.end());
        
    }
};