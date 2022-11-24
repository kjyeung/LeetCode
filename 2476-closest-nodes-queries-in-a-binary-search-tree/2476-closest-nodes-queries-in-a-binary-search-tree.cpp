/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> nums;
        flatten(root, nums);
        vector<vector<int>> res;
        for(int q : queries){
            auto left = lower_bound(nums.begin(), nums.end(), q);
            if(left != nums.end() && *left == q) res.push_back({q, q});
            else if(left == nums.end()) res.push_back({nums.back(), -1});
            else if(left == nums.begin()) res.push_back({-1, nums.front()});
            else res.push_back({*prev(left), *left});
        }
        return res;
        
    }
    void flatten(TreeNode* root, vector<int>& nums){
        if(root == nullptr) return;
        flatten(root->left, nums);
        nums.push_back(root->val);
        flatten(root->right, nums);
        return;
    }
};