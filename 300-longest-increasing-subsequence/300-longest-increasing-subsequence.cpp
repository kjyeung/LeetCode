class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> table(nums.size(), 1);

        for(int i = 1; i < table.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && table[i] < table[j] + 1) table[i] = table[j] + 1;
            }
            
        }
        return *max_element(table.begin(), table.end());
    }
};