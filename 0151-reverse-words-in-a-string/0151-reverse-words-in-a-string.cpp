class Solution {
public:
    string reverseWords(string s) {
        removeSpace(s);
        int start = 0;
        int end = s.size() - 1;
        while(start < end) swap(s[start++], s[end--]);
        start = 0;
        while (start < s.size()){
            int left = start, right = start;
            while(right < s.size() && s[right] != ' ') ++right;
            start = right + 1;
            --right;
            while(left < right) swap(s[left++],s[right--]);
        }

        return s;
    }
    
    void removeSpace(string& s){
        int slow = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ' && (slow == 0 || (slow > 0 && s[slow - 1] == ' ')))  continue;
            s[slow++] = s[i];
        }
        s = s.substr(0, slow);
        if(s.back() == ' ') s.pop_back();
        return;
    }
};