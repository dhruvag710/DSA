class Solution {
public:
    bool check(TreeNode* left, TreeNode* right)
    {
        if(left==nullptr || right==nullptr) return left==right;

        if(left->val!=right->val) return false;

        return check(left->left, right->right) && check(left->right, right->left);


    }



    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;

        return check(root->left, root->right);        
    }
};