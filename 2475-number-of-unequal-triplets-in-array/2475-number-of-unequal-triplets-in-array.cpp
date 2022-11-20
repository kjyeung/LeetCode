class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int,int> table;
        for(int n : nums){
            ++table[n];
        }
        int left = 0, right = nums.size(), res = 0;
        for(auto [num ,cnt] :table){
            right -= cnt;
            res += left * cnt * right;
            left += cnt;
        }
        
        return res;
    }
};