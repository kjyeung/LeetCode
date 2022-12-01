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
    unordered_map<int,int> postidx;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        for(int i = 0; i < n; i++){
            postidx[postorder[i]] = i;
        }
        return cfpp(preorder, 0, n - 1, postorder, 0, n - 1);
    }
    
    TreeNode* cfpp(vector<int>& preorder, int preleft, int preright, vector<int>& postorder, int postleft, int postright){
        if(preleft > preright || postleft > postright) return nullptr;
        if(preleft == preright || postleft == postright){
            return new TreeNode(preorder[preleft]);
        }
        int rootval = preorder[preleft];
        TreeNode* root = new TreeNode(rootval);
        int subrootval = preorder[preleft + 1];
        int subrootpostidx = postidx[subrootval];
        int leftsize = subrootpostidx - postleft ;
        root->left = cfpp(preorder, preleft + 1, preleft + leftsize + 1, postorder, postleft, subrootpostidx);
        root->right = cfpp(preorder, preleft + leftsize + 2, preright, postorder,subrootpostidx + 1, postright - 1);
        return root;
    }
};