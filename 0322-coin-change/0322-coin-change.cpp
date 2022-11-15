class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //int table[amount + 1];
        //memset(table, amount + 1, sizeof(table));
        vector<int> table(amount + 1, amount + 1);
        table[0] = 0;
        for(int i = 1; i < amount + 1; i++){
            for(int c : coins){
                if(i - c < 0) continue;
                table[i] = min(table[i - c] + 1, table[i]);
                
            }
        }
        return table[amount] == amount + 1? -1 : table[amount];
    }
};