class Solution {
public:
    TreeNode* lastVisited=NULL;
    void flatten(TreeNode* root) {
        if(root==NULL) return;

        flatten(root->right);
        flatten(root->left);

        root->left=NULL;
        root->right=lastVisited;
        lastVisited=root;
    }
};