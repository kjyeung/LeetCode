class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b){
           return a[0]<b[0]  || (a[0] ==b[0] && a[1] >b[1]);
        });
        
        vector<int> tmp;
        for(const vector<int>& e : envelopes){
            int v = e[1];
            if(tmp.empty()) tmp.push_back(v);
            else{
                int left = 0, right = tmp.size(); 
                while(left < right){
                    int mid = left + (right - left) / 2;
                    if(tmp[mid] > v) right = mid;
                    else if(tmp[mid] < v) left = mid + 1;
                    else right = mid;
                }
                if(left == tmp.size()) tmp.push_back(v);
                else tmp[left] = v;
            }
        }
        return tmp.size();
        
    }
};