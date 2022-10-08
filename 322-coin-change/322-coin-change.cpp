class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ret = 0;
        vector<int> table(amount + 1, amount + 1);
        table[0] = 0;
        for(int i = 0; i < table.size(); i++){
            for(int c : coins){
                if(i - c < 0) continue;
                table[i] = min(table[i], table[i - c] + 1);
            }
        }
        return table[amount] == amount + 1? -1 : table[amount];
    }
};