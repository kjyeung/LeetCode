class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
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