class Solution {
public:
    int size;
    unordered_map<int,int> table;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;
    
    Solution(int n, vector<int>& blacklist) {
        size = n - blacklist.size();
        
        for(int & b : blacklist){
            table[b] = 777;
        }
        
        int last = n - 1;
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