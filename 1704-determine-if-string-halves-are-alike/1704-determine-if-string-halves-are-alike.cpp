class Solution {
public:
    bool halvesAreAlike(string s) {
        set<char> table{'a', 'e', 'i', 'o','u', 'A', 'E', 'I', 'O', 'U'};
        int count = 0;
        int n = s.size();
        for(int i = 0; i < n / 2; i++){
            if(table.count(s[i])) ++count;
            
        }
        for(int i = n / 2 ; i < n; i++){
            if(table.count(s[i])) --count;
        }
        return count == 0? true:false;
        
    }
};