class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ret = 0, sum = 0;
        unordered_map<int,int> table;
        int n = nums.size();
        
        int left = 0;
        for(int i  = 0; i < n; i++){
           if(table.count(nums[i])){
               int idx = table[nums[i]];
               for(int j = left; j <= idx; j++){
                   table.erase(nums[j]);
                   sum -= nums[j];
               }
               left = idx + 1;
               table[nums[i]] = i;
               sum += nums[i];
           }else{
               if(table.size() == k){
                   sum -= nums[left];
                   table.erase(nums[left]);
                   ++left;
               }
               table[nums[i]]  = i;
               sum += nums[i];
               
           }
           if(table.size() == k) ret = max(ret, sum);
        }
        return ret;
        
    }
};