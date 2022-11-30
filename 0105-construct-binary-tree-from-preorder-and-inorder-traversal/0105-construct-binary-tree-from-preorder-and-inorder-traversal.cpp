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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        int idx = 0;
        
        for(int i = 1; i < preorder.size(); i++){
            TreeNode* cur = stk.top();
            if(cur->val != inorder[idx]){
                cur->left = new TreeNode(preorder[i]);
                stk.push(cur->left);
            }else{
                while(!stk.empty() && stk.top()->val == inorder[idx]){
                    cur = stk.top();
                    stk.pop();
                    ++idx;
                }
                cur->right = new TreeNode(preorder[i]);
                stk.push(cur->right);
            }
        }
        return root;
        
    }
};