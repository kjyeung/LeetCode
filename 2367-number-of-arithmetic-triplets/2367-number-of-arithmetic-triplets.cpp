class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int res = 0;
        vector<bool> table(201, false);
        for(int i = 0; i < nums.size(); i++){
            table[nums[i]] = true;
            if(nums[i] < 2 *diff) continue;
            if(table[nums[i] - diff] && table[nums[i]-2*diff]) ++res;
        }
        return res;
        
        
    }
};