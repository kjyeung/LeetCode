class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> all(256, 0);
        vector<bool> in(256, false);
        for(char c : s){
            ++all[c];
        }
        string res;
        for(char c : s){
            --all[c];
            if(in[c]) continue;
            
            while(!res.empty() && res.back() >= c && all[res.back()] > 0){
                in[res.back()] = false;
                res.pop_back();
            }
            res.push_back(c);
            in[c] = true;
        }

        return res;
        
        
    }
};