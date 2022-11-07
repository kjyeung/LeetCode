class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            if(nums[i] ==nums[i + 1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        
        int fast = 0, slow = 0;
        while(fast < n){
            if(nums[fast]!= 0) swap(nums[fast], nums[slow++]);
            ++fast;
        }
        return nums;
    }
};