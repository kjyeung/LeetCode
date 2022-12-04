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
        stack<TreeNode*> stk;
        TreeNode* root = new TreeNode(preorder[0]);
        stk.push(root);
        int idx = 0;
        for(int i =1; i < preorder.size();i++){
            while(stk.top()->val == postorder[idx]){
                stk.pop();
                ++idx;
            }
            TreeNode* next = new TreeNode(preorder[i]);
            if(!stk.top()->left) stk.top()->left = next;
            else stk.top()->right = next;
            stk.push(next);
        }
        return root;
        
        
    }
};