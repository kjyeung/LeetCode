class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        while(right < n){
            if(nums[right] != nums[left]){
                ++left;
                swap(nums[left], nums[right]);
            }
            ++right;
        }
        return left+1;
    }
};