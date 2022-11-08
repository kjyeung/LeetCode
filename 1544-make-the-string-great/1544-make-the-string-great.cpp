class Solution {
public:
    string makeGood(string s) {
        if(s.empty()) return s;
        deque<char> q;
        string res;
        for(char c :s){
            if(q.empty()){
                q.push_back(c);
            }else{
                if(abs(c - q.back())== abs('A' - 'a')){
                    q.pop_back();
                }else{
                   q.push_back(c);
                }
            }
        }
        while(!q.empty()){
            res += q.front();
            q.pop_front();
        }
        return res;
        
    }
};