class Solution {
public:
    
    int calc(vector<int>& piles, int x){
        int ret = 0;
        for(int p : piles){
            ret += (p + x - 1) / x;
        }
        return ret;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1000000000+1;
        while(left < right){
            int mid = left + (right - left) / 2;
            int t = calc(piles, mid);
            if(t > h){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return right;
    }
};