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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder.front());
        stack<TreeNode*> stk;
        stk.push(root);
        int idx = 0;
        for(int i = 1; i < preorder.size(); i++){
            TreeNode* cur = new TreeNode(preorder[i]);
            while(stk.top()->val == postorder[idx]){
                stk.pop();
                ++idx;
            }
            if(stk.top()->left == nullptr) stk.top()->left = cur;
            else stk.top()->right = cur;
            stk.push(cur);
        }
        return root;
        
    }
};