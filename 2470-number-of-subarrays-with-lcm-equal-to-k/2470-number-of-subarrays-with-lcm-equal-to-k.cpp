class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int res = 0;
        int left = 0;
        int cur_max_idx = -1;
        for (int right = 0; right < nums.size(); ++right) {
            auto num = nums[right];
            if (num > k || k%num != 0) {
                left = right + 1;
                //cout<<"skip:"<<right<<" num:"<<num<<" \n";
                continue;
            }
            if (num == k) {
                //cout<<"num == k idx:"<< right<<endl;
                cur_max_idx = right;
            }
            if (cur_max_idx >= left) {
                //cout<<"cur_max_idx:"<<cur_max_idx<< " left:"<<left<<endl;
                res += cur_max_idx-left+1;
            }
                
        }
        return res;
    }
};