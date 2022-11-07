class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[256];
        memset(count, 0, sizeof(count));
        bool in[256];
        memset(in, false, sizeof(in));
        stack<char> stk;
        string res;
        for(char & c : s){
            ++count[c];
        }
        
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            --count[c];
            if(in[c]) continue;
            while(!stk.empty() && stk.top() > c && count[stk.top()] >0){
                in[stk.top()] = false;
                stk.pop();
            }
            stk.push(c);
            in[c] = true;
        }
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};