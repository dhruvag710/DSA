class Solution {
public:
    int dfs(TreeNode* root, int num) {
        if (root == nullptr) return 0;

        num = num * 10 + root->val;

        if (root->left == nullptr && root->right == nullptr)
            return num;

        return dfs(root->left, num) + dfs(root->right, num);
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};