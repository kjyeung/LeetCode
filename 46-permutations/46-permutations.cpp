class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        bt(nums, 0, n);
        return res;
    }
    
    void bt(vector<int>& nums, int left ,int right){
        if(left == right){
            res.push_back(nums);
        }
        
        for(int i = left; i < right ;i++){
            swap(nums[left],nums[i]);
            bt(nums, left + 1, right);
            swap(nums[left], nums[i]);
        }
        return;
    }
};