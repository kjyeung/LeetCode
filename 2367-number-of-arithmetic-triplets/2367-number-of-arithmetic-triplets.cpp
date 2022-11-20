class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n - 2; i++){
            for(int j = i + 1; j < n - 1 && nums[j] - nums[i] <= diff; j++){
                if(nums[j] - nums[i] != diff) continue;
                for(int k = j + 1; k < n && nums[k] - nums[j] <= diff; k++){
                    if(nums[k] - nums[j] == diff) ++res;
                }
            }
        }
        return res;
        
    }
};