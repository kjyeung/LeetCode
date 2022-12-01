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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(postorder.back());
        stack<TreeNode*> stk;
        stk.push(root);
        int idx = inorder.size() - 1;
        for(int i = postorder.size() - 2; i>=0; i--){
            TreeNode* cur = stk.top();
            if(cur->val != inorder[idx]){
                cur->right = new TreeNode(postorder[i]);
                stk.push(cur->right);
            }else{
                while(!stk.empty() && stk.top()->val == inorder[idx]){
                    cur = stk.top();
                    stk.pop();
                    --idx;
                }
                cur->left= new TreeNode(postorder[i]);
                stk.push(cur->left);
            }
        }
        
        return root;
        
    }
};