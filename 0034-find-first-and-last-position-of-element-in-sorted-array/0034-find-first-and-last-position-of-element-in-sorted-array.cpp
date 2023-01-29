class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
        vector<int> res;
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid]<target) left = mid + 1;
            else if(nums[mid] > target) right = mid - 1;
            else right = mid - 1;
        }
        if(left == nums.size() || nums[left] != target) left = -1;
        res.push_back(left);
        
        left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid]<target) left = mid + 1;
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1; 
        }
        
        if(left  - 1 < 0 || nums[left - 1] != target) left = -1;
        else left -= 1;
        res.push_back(left);
        return res;
        
        
    }
};