class Solution {
public:
    string reverseWords(string s) {
        istringstream input(s);
        stack<string> stk;
        string res;
        string tmp;
        while(input >> tmp){
            stk.push(tmp);
        }
        while(!stk.empty()){
            res += stk.top() + ' ';
            stk.pop();
        }
        res.pop_back();
        return res;
        
    }
};