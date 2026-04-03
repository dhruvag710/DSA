class BSTIterator {
public:
    stack<TreeNode*>s;

    void storeLeftNodes(TreeNode* root)
    {
        while(root!=nullptr)
        {
            s.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        storeLeftNodes(root);
    }
    
    int next() {
        TreeNode* ans=s.top();
        s.pop();

        storeLeftNodes(ans->right);
        return ans->val;
    }
    
    bool hasNext() {
        if(s.size()>0) return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */