class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        backtrack(nums, res, 0, n);
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<vector<int>>& res, int start, int end){
        if(start == end){
            res.push_back(nums);
        }
        for(int i = start; i < end; i++){
            swap(nums[start], nums[i]);
            backtrack(nums, res, start + 1, end);
            swap(nums[start], nums[i]);
        }
        return;
    }
};