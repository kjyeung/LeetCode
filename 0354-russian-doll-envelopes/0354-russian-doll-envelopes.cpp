class Solution {
public:
    struct comp{
        bool operator()(vector<int>& a, vector<int>& b){
            if(a[0]==b[0]) return a[1] >= b[1];
            return a[0] < b[0];
        }
    };
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp());
        vector<int> tmp;
        for(vector<int>& env : envelopes){
            if(tmp.empty()){
                tmp.push_back(env[1]);
                continue;
            }
            int left = 0, right = tmp.size();
            while(left < right){
                int mid = left + (right - left) / 2;
                if(tmp[mid] > env[1]){
                    right = mid;
                }else if(tmp[mid] < env[1]){
                    left = mid + 1;
                }else right = mid;
            }
            if(left == tmp.size()) tmp.push_back(env[1]);
            else tmp[right] = env[1];
        }
        return tmp.size();
    }
};