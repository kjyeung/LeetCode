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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return cmbt(nums, 0, n - 1);
    }
    
    TreeNode* cmbt(vector<int>& nums, int left , int right){
        if(left > right) return nullptr;
        int max = nums[left];
        int rootidx = left;
        for(int i = left; i <= right; i++){
            if(nums[i] > max){
                max = nums[i];
                rootidx = i;
            }
        }
        
        TreeNode* root = new TreeNode(max);
        root->left = cmbt(nums, left, rootidx - 1);
        root->right = cmbt(nums, rootidx + 1, right);
        return root;
        
    }
};