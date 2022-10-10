class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n ==1) return "";
        string res = palindrome;
        bool changed = false;
        for(int i = 0; i < n / 2; i++){
            if(res[i] > 'a'){
                res[i]  = 'a';
                changed = true;
                return res;
            }
        }
        res.back() = 'b';
        
        return res;
    }
};