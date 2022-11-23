class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        unordered_map<int,int> table;
        int res = 0;
        for(int num : nums){
            unordered_map<int,int> tmp;
            if(num % k == 0){
                ++table[num];
                for(auto &[x, cnt] : table){
                    tmp[gcd(x, num)] += cnt;
                }
                res += tmp[k];
            }
            swap(table, tmp);
        }
        return res;
        
    }
};