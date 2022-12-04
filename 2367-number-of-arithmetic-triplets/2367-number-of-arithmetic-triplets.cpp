class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        vector<bool> in(201, false);
        int res = 0;
        for(int i = 0; i < nums.size();i++){
            in[nums[i]] = true;
            if(nums[i] >= 2*diff && in[nums[i] - diff] && in[nums[i] - 2*diff]) ++res;
        }
        return res;
        
    }
};