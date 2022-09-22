class Solution {
public:
    int calc(vector<int>& weights, int x){
        int ret = 1;
        int sum = 0;
        for(int & w : weights){
            if(sum + w > x){
                sum = 0;
                ++ret;
            }
            sum += w;
        }
        return ret;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end()), right = accumulate(weights.begin(), weights.end(), 1);
        while(left < right){
            int mid = left + (right - left) / 2;
            int t = calc(weights, mid);
            if(t > days){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};