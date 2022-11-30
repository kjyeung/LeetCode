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
        int n = postorder.size();
        int idx = n -1;
        for(int i = n - 2; i >=0;i--){
            TreeNode* cur = stk.top();
            int postval = postorder[i];
            if(cur->val != inorder[idx]){
                cur->right = new TreeNode(postval);
                stk.push(cur->right);
            }else{
                while(!stk.empty() && stk.top()->val == inorder[idx]){
                    cur = stk.top();
                    stk.pop();
                    --idx;
                }
                cur->left = new TreeNode(postval);
                stk.push(cur->left);
            }
        }
        return root;
    }
};