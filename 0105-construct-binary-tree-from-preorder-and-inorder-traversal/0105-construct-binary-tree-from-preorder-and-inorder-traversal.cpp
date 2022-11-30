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
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        int idx = 0;
        for(int i = 1; i < preorder.size(); i++){
            int preval = preorder[i];
            TreeNode* node = stk.top();
            if(node->val != inorder[idx]){
                node->left = new TreeNode(preval);
                stk.push(node->left);
            }else{
                while(!stk.empty() && stk.top()->val == inorder[idx]){
                    node = stk.top();
                    stk.pop();
                    ++idx;
                }
                node->right = new TreeNode(preval);
                stk.push(node->right);
            }
        }
        return root;
        
    }
};