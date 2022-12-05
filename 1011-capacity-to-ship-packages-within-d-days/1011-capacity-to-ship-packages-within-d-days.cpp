class Solution {
public:
    int calc(vector<int>& weights, int x){
        int ret = 1;
        int sum = 0;
        for(int w : weights){
            if(sum + w > x){
                ret += 1;
                sum = 0;
            }
            sum += w;
        }
        return ret;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while(left < right){
            int mid = left + (right - left ) / 2;
            int t = calc(weights, mid);
            if(t <= days){
                right = mid;
            }else left = mid + 1;
        }
        return left;
        
    }
};