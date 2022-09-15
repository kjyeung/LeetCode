class Solution {
public:
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;
    int size;
    unordered_map<int,int> table;
    
    Solution(int n, vector<int>& blacklist) {
        std::random_device rd;
        gen = std::mt19937(rd());
        
        int size = n - blacklist.size();
        dis = std::uniform_int_distribution<>(0, size - 1);
        
        for(int &b : blacklist){
            table[b] = 777;
        }
        int last = n - 1;
        for(int &b : blacklist){
            if(b >= size) continue;
            while(table.count(last)) --last;
            table[b] = last--;
        }
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