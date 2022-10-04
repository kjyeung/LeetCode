class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(256);
        vector<bool> in(256);
        for(char c: s){
            ++count[c];
        }
        
        string tmp;
        for(char c : s){
            --count[c];
            if(in[c]) continue;
            while(!tmp.empty() && tmp.back() > c && count[tmp.back()] > 0){
                in[tmp.back()] = false;
                tmp.pop_back();
            }
            tmp.push_back(c);
            in[c] = true;            
        }
        return tmp;
        
        
    }
};