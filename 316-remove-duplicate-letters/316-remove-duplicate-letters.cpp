class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(256);
        vector<bool> in(256);
        for(char c : s){
            ++count[c];
        }
        
        string res;
        for(char c : s){
            --count[c];
            if(in[c]) continue;
            while(!res.empty() && res.back() >= c && count[res.back()] > 0){
                in[res.back()] = false;
                res.pop_back();
            }
            res.push_back(c);
            in[c] = true;
        }
        return res;
    }
};