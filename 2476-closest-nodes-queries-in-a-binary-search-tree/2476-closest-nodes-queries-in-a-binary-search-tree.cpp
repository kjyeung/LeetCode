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
    vector<int> nums;
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        flatten(root);
        vector<vector<int>> res;
        for(int & q : queries){
            auto it = lower_bound(nums.begin(), nums.end(), q);
            if(it != nums.end() && *it == q){
                res.push_back({q, q});
            }else{
                res.push_back({it == nums.begin()? -1 : *prev(it), it == nums.end()? -1 : *it});
            }
        }
        return res;
        
    }
    void flatten(TreeNode* root){
        if(root == nullptr) return;
        flatten(root->left);
        nums.push_back(root->val);
        flatten(root->right);
        return;
    }
};