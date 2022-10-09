class Solution {
public:
    struct comp{
        bool operator()(vector<int>& a, vector<int> &b){
            if(a[0] == b[0]) return a[1] >= b[1];
            return a[0] < b[0];
            
        }
    };
    int maxEnvelopes(vector<vector<int>>& envelopes) {
         sort(envelopes.begin(), envelopes.end(), comp());
        int ret = 0;
        int n = envelopes.size();
        vector<int> tmp;
        for(int i = 0; i < n; i++){
            if(tmp.empty())
            {
                tmp.push_back(envelopes[i][1]);
                continue;
            }
            int left = 0, right = tmp.size();
            while(left < right){
                int mid = left + (right - left) /2;
                if(tmp[mid] > envelopes[i][1]){
                    right = mid;
                }else if(tmp[mid] < envelopes[i][1]){
                    left = mid + 1;
                }else right = mid;
            }
            if(left == tmp.size()) tmp.push_back(envelopes[i][1]);
            else tmp[right] = envelopes[i][1];
        }
        
        return tmp.size();
    }
};