class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = nums[0], second = INT_MAX;
        for(int i= 1; i < nums.size(); i++){
            if(nums[i] >second) return true;
            else{
                if(nums[i] >first) second = nums[i];
                else first = nums[i];
            } 
        }
        return false;
    }
};