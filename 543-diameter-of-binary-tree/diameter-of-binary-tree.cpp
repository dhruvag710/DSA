class Solution {
public:
    int height(TreeNode* root)
    {
        if(root==nullptr) return 0;

        int lh=height(root->left);
        int rh=height(root->right);

        return max(lh,rh)+1;
    }



    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;

        int leftDia=diameterOfBinaryTree(root->left);
        int rightDia=diameterOfBinaryTree(root->right);

        int currDia=height(root->left)+height(root->right);
        return max(leftDia, max(rightDia, currDia));
    }
};