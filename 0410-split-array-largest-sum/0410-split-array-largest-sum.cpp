class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        while(left < right){
            int mid = left + (right - left)/ 2;
            int t = calc(nums, mid);
            if(t > k){
                left = mid + 1;
            }else if(t < k){
                right = mid;
            }else right = mid;
        }
        return left;
    }
    int calc(vector<int>& nums, int x){
        int sum = 0;
        int ret = 1;
        for(int num : nums){
            if(sum + num > x){
                ret += 1;
                sum = 0;
            }
            sum += num;
        }
        return ret;
    }
};