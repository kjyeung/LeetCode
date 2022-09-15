class Solution {
private:
    unordered_map<int,int> table;
    int size;
    
public:
    Solution(int n, vector<int>& blacklist) {
        int k = blacklist.size();
        int last = n - 1;
        size = n - k;
        for(int & b : blacklist){
            table[b] = -777;
        }
        
        for(int & b : blacklist){
            if(b >= size) continue;
            while(table.count(last)) --last;
            table[b] = last--;
        }
        
    }
    
    int pick() {
        int num = rand() % size;
        if(table.count(num)) return table[num];
        return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */