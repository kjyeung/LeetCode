class Solution {
public:
    struct sw{
        int maxnum;
        deque<int> q;
        
        void push(int x){
            while(!q.empty() && q.back() < x) q.pop_back();
            q.push_back(x);
        }
        
        void pop(int x){
            if(q.front() == x) q.pop_front();
            return;
        }
        int max(){
            return q.front();
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        sw a = sw();
        vector<int> res;
        for(int i = 0; i < k - 1; i++){
            a.push(nums[i]);
        }
        for(int i = k-1; i < nums.size(); i++ ){
            a.push(nums[i]);
            res.push_back(a.max());
            a.pop(nums[i - k+1]);
        }
        return res;
        
        
    }
};