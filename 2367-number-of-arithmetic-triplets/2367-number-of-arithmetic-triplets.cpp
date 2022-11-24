class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int res = 0;
        vector<bool> table(201, false);
        for(int i = 0; i < nums.size(); i++){
            table[nums[i]] = true;
            if(nums[i] >= diff * 2 && table[nums[i] - diff] && table[nums[i] - diff * 2]) ++ res;
        }
        return res;
        
    }
};