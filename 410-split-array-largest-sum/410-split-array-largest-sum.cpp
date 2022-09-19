class Solution {
public:
    int calc(vector<int>& nums, int m){
        int ret = 1;
        int sum = 0;
        for(int & num : nums){
            if(sum + num > m){
                ret += 1;
                sum = 0;
            }
            sum+=num;
        }
        return ret;
    }
    int splitArray(vector<int>& nums, int m) {
        int left = *max_element(nums.begin(), nums.end()), right = accumulate(nums.begin(), nums.end(), 1);
        while(left < right){
            int mid = left + (right - left) / 2;
            int t = calc(nums, mid);
            if(t > m){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};