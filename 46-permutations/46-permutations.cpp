class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> track;
        vector<bool> used(n);
        backtrack(nums, track ,used);
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<int>& track, vector<bool>& used){
        if(track.size() == nums.size()){
            res.push_back(track);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;
            track.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, track, used);
            track.pop_back();
            used[i] = false;
        }
        return;
    }
};