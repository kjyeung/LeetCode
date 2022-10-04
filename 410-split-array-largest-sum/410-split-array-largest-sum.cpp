class Solution {
public:
    int calc(vector<int>& nums, int x){
        int ret = 1;
        int sum = 0;
        for(int num : nums){
            if(sum + num > x){
                ret += 1;
                sum = 0;
            }
            sum += num;
        }
        return ret;
    }
    int splitArray(vector<int>& nums, int m) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 1);
        while(left < right){
            int mid = left + (right - left) / 2;
            int sum = calc(nums, mid);
            if(sum > m){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};