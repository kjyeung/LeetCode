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
        return bt(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* bt(vector<int>&preorder, int preleft, int preright, vector<int>& inorder, int inleft, int inright){
        if(preleft > preright || inleft > inright) return nullptr;
        int rootval = preorder[preleft];
        int inroot = inleft;
        for(int i = inleft; i <= inright; i++){
           if(inorder[i] == rootval){
               inroot = i;
               break;
           }
        }
        int leftsize = inroot - inleft;
        TreeNode* ret = new TreeNode(rootval);
        ret->left= bt(preorder, preleft + 1, preleft + leftsize, inorder, inleft, inroot - 1);
        ret->right = bt(preorder, preleft + leftsize+1, preright, inorder, inroot+1, inright) ;
        
        return ret;
    }
};