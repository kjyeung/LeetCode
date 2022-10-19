class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> table(amount + 1, amount + 1);
        table[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int c : coins){
                if(i - c < 0) continue;
                table[i] = min(table[i], 1 + table[i - c]);
            }
        }
        return table[amount] == amount + 1? -1:table[amount];
    }
};