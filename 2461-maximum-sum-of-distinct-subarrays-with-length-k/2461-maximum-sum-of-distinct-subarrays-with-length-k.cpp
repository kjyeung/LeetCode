class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ret = 0, sum = 0;
        unordered_map<int,int> table;
        int n = nums.size();
        
        int left = 0, right = 0;
        
        while(right < n){
            long long cur = nums[right];
            table[cur] += 1;
            sum += cur;
            ++right;
            while(table[cur] > 1 || right - left > k){
                long long pop = nums[left];
                sum -= pop;
                --table[nums[left]];
                ++left;
            }
            if(right - left == k){
                ret = max(ret, sum);
            }
            
            
        }
        return ret;
        
    }
};