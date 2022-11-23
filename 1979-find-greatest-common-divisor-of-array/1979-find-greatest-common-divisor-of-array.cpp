class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minval = INT_MAX;
        int maxval = INT_MIN;
        for(int num : nums){
            minval = min(minval, num);
            maxval = max(maxval, num);
        }
        return gcd(minval, maxval);
    }
    int gcd(int a, int b){
        while(b^=a^=b^=a%=b){}
        return a;
    }
};