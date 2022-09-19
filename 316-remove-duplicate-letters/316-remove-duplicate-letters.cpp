class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res;
        if(s.empty()) return res;
        vector<int> count(256);
        vector<bool> in(256);
        for(char c : s){
            ++count[c];
        }
        
        for(char c : s){
            --count[c];
            if(in[c]) continue;
            while(!res.empty() && res.back() > c && count[res.back()]) {
                in[res.back()] = false;
                res.pop_back();
            }
            res.push_back(c);
            in[c] = true;
        }
        
        return res;
    }
};