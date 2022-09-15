class Solution {
private:
    unordered_map<int,int> table;
    int size;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;
    
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
        
        std::random_device rd; 
        gen = std::mt19937(rd()); 
        dis = std::uniform_int_distribution<>(0, size - 1);
        
    }
    
    int pick() {
        int num = dis(gen);
        if(table.count(num)) return table[num];
        return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */