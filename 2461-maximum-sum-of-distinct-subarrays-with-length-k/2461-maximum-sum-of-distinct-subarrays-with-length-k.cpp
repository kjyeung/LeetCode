class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *(max_element(nums.begin(), nums.end()));
        vector<int> count(mx + 1);
        int dupCount = 0;
        int64_t sum = 0;
        int len = 0;
        int64_t ret = 0;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            sum += num;
            count[num] += 1;
            if (count[num] == 2) {
                dupCount += 1;
            }
            len += 1;
            
            if (len == k + 1) {
                int oldNum = nums[i - k];
                sum -= oldNum;
                count[oldNum] -= 1;
                if (count[oldNum] == 1) {
                    dupCount -= 1;
                }
                len -= 1;
            }
            
            if (len == k && dupCount == 0) {
                ret = max(ret, sum);
            }
        }
        return ret;
    }
};