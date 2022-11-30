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
    unordered_map<int,int> intable;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i = 0; i < inorder.size();i++){
            intable[inorder[i]] = i;
        }
        return bt(inorder, 0, n - 1, postorder, 0, n - 1);
    }
    TreeNode* bt(vector<int>& inorder, int inleft ,int inright, vector<int>& postorder, int postleft, int postright){
        if(inleft > inright || postleft > postright) return nullptr;
        int rootval = postorder[postright];
        TreeNode* root = new TreeNode(rootval);
        int inroot = intable[rootval];
        int leftsize = inroot - inleft - 1;
        root->left = bt(inorder, inleft, inroot - 1, postorder, postleft, postleft + leftsize);
        root->right =bt(inorder, inroot + 1, inright, postorder, postleft + leftsize + 1, postright - 1);
        return root;
    }
};