class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        for(int i = 0; i < k - 1; i++){
            while(!q.empty() && nums[i] > nums[q.back()]) q.pop_back();
            q.push_back(i);
        }
        vector<int> res;
        for(int i = k - 1; i < nums.size(); i++){
            while(!q.empty() && nums[i] > nums[q.back()]) q.pop_back();
            q.push_back(i);
            res.push_back(nums[q.front()]);
            if(q.front() == i - k +1) q.pop_front();
        }
        return res;
    }
};