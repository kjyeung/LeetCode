class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> table;
        for(int & num : nums){
            if(table.empty()) table.push_back(num);
            else{
                int left = 0, right = table.size();
                while(left < right){
                    int mid = left + (right - left) / 2;
                    if(table[mid] > num){
                        right = mid;
                    }else if(table[mid] == num){
                        right = mid;
                    }else{
                        left = mid + 1;
                    }
                }
                if(left == table.size()) table.push_back(num);
                else table[right] = num;
            }
        }
        return table.size();
    }
};