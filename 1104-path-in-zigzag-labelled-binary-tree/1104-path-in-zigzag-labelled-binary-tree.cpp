class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        while(label > 1){
            res.push_back(label);
            int level = log2(label);
            int upstair_low = pow(2, level - 1) ;
            int upstair_high = pow(2, level) - 1;
            label = upstair_high - (label / 2 - upstair_low);
        }
        res.push_back(1);
        reverse(res.begin(), res.end());
        return res;
    }
};