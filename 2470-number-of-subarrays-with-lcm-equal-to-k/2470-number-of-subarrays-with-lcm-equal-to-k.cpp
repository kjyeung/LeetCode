class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int,int> m;
        for(int i = 0, j = 0; i < nums.size(); ++i){
            ++m[nums[i]];
            unordered_map<int,int> m1;
            for(auto [d, cnt] : m){
                int lcm = d * nums[i] / gcd(d,nums[i]);
                if(lcm == k)
                    res += cnt;
                if(k % lcm == 0)
                    m1[lcm] += cnt;
                
            }
            swap(m , m1);
            
        }
        return res;
        
    }
};