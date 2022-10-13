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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* pre = nullptr;
        vector<int> res;
        if(root == nullptr) return res;
        while(root){
            if(root->left){
                pre = root->left;
                while(pre->right && pre->right != root){
                    pre = pre->right;
                }
                if(pre->right == nullptr){
                    pre->right = root;
                    res.push_back(root->val);
                    root = root->left;
                }else{
                    pre->right = nullptr;
                    root = root->right;
                }
            }else{
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};