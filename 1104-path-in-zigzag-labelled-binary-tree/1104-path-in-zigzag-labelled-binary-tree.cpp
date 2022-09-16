class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        while(label >= 1){
            res.push_back(label);
            int level = log2(label);
            int max = pow(2, level) - 1;
            int min = pow(2, level - 1);
            label = max - (label / 2 - min);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};