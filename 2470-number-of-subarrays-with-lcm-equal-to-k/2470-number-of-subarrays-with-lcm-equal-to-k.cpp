class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int res = 0;
        int n = nums.size();
        int tmp = nums[left];
        while(right < n){
            int cur = nums[right];
            if(cur == k) ++res;
            ++right;
            if(cur > k || k % cur || right == n){
                while(left < right){
                    int prev = nums[left];
                    for(int i = left + 1; i < right; i++) {
                        prev = lcm(prev, nums[i]);
                        if(prev == k) res += 1;
                    }
                    ++left;
                }
            }else{
                
            }
            
             
            
        }
        
        return res;
        
    }
    
    int gcd(int a, int b){
        while(b^=a^=b^=a%=b);
        return a;
    }
    int lcm (int a, int b){
        return a/gcd(a, b)*b;
    }
    

};