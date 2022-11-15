class Solution {
public:
    string reverseWords(string s) {
        removeSpace(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        while(start < s.size()){
            int left = start;
            int right = left;
            while(right < s.size() && s[right] != ' ') ++right;
            start = right + 1;
            reverse(s, left, right - 1);
        }
        return s;
        
    }
    void removeSpace(string & s){
        int slow = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ' && (slow == 0 || (slow > 0 && s[slow - 1] == ' '))) continue;
                s[slow++] = s[i];
        }
        s = s.substr(0, slow);
        if(s.back() == ' ') s.pop_back();
    }
    
    void reverse(string & s, int left, int right){
        if(left >= right) return;
        while(left < right) swap(s[left++], s[right--]);
    }
};