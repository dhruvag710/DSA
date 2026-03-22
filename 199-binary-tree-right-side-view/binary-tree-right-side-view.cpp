class Solution {
public:
    void right(TreeNode* root, vector<int>& res, int level)
    {
        if(root==nullptr) return;
        if(res.size()==level) res.push_back(root->val);
        right(root->right, res, level+1);
        right(root->left, res, level+1);


    }



    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        right(root, res,0);
        return res;
    }
};