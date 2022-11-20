class Solution {
public:
    vector<vector<int>> res;
    vector<int> flat;
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        traverse(root);
        
        for(int & q : queries){
            auto it = lower_bound(flat.begin(), flat.end(), q);
            if (it != flat.end() && *it == q) 
                res.push_back({q, q});
            else
                res.push_back({it == flat.begin()? -1 : *prev(it), it == flat.end()? -1 : *it});
        }
        return res;
        
    }
    void traverse(TreeNode* root){
        if(root == nullptr) return;
        traverse(root->left);
        flat.push_back(root->val);
        traverse(root->right);
        return;
    }
};