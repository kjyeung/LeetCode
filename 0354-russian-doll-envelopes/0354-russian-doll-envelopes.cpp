struct comp{
    bool operator()(vector<int>& a, vector<int>&b){
        if(a[0] < b[0]) return true;
        if(a[0] == b[0]) return a[1] >= b[1];
        return false;
    }
};
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp());
        vector<int> tmp;
        for(vector<int>& e : envelopes){
            if(tmp.empty()){
                tmp.push_back(e[1]);
                continue;
            }
            int left = 0, right = tmp.size();
            while(left < right){
                int mid = left + (right - left) / 2;
                if(tmp[mid]>e[1]){
                    right = mid;
                }else if(tmp[mid] == e[1])right = mid;
                else left = mid + 1;
            }
            if(left == tmp.size()) tmp.push_back(e[1]);
            tmp[left] = e[1];
        }
        return tmp.size();
        
    }
};