class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        string res = palindrome;
        bool changed = false;
        for(int i = 0; i < n / 2; i++){
            if(res[i] > 'a'){
                res[i]  = 'a';
                changed = true;
                return res;
            }
        }
        int start = 0;
        if(n % 2) start = n / 2 + 1;
        else start = n / 2;
        for(int i = start; i<n;i++){
            if(res[i] > 'a'){
                res[i] = 'a';
                changed = true;
                return res;
            }
        }
        if(res.size() > 1 && res.back() == 'a'){
            res.back() = 'b';
            return res;
        }
        if(!changed) return "";
        return res;
    }
};