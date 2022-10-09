class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tmp;
        for(int i = 0; i < nums.size(); i++){
            if(tmp.empty()){
                tmp.push_back(nums[i]);
                continue;
            }
            
            int left = 0, right = tmp.size();
            while(left < right){
                int mid = left + (right - left) / 2;
                if(tmp[mid] < nums[i]){
                    left = mid + 1;
                }else right = mid;
            }
            
            if(left == tmp.size()){
                tmp.push_back(nums[i]);
            }else{
                tmp[right] = nums[i];
            }
        }
        return tmp.size();
    }
};