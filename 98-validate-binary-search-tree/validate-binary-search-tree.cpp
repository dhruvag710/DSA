class Solution {
public:
    bool validate(TreeNode* root, long long maxi, long long mini)
    {
        if(root==nullptr) return true;


        if(root->val>= maxi || root->val<=mini) return false;

        return validate(root->left, root->val, mini) && validate(root->right, maxi, root->val);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MAX, LLONG_MIN);
    }
};