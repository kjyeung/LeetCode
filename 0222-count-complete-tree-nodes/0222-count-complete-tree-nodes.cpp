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
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        int hl = 0, hr = 0;
        while(l){
            ++hl;
            l = l->left;
        }
        while(r){
            ++hr;
            r = r->right;
        }
        if(hl == hr) return pow(2, hl + 1) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
        
    }
};