class Solution {
public:
    void parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_check)
    {
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* current=q.front();
            q.pop();
            if(current->left)
            {
                parent_check[current->left]=current;
                q.push(current->left);
            }
            if(current->right)
            {
                parent_check[current->right]=current;
                q.push(current->right);
            }
        }
    }
    TreeNode* findNode(TreeNode* root, int start) 
    {
    if(root == NULL) return NULL;
    if(root->val == start) return root;

    TreeNode* left = findNode(root->left, start);
    if(left) return left;

    return findNode(root->right, start);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent_check;
        parent(root, parent_check);
        queue<TreeNode*>q;
        unordered_map<TreeNode*, bool> visited;
        TreeNode* current= findNode(root, start);
        q.push(current);
        visited[current]=true;
        int time=0;

        while(!q.empty())
        {
             bool spread=false;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode*curr=q.front();
                q.pop();

                if(curr->left && !visited[curr->left])
                {
                    q.push(curr->left);
                    visited[curr->left]=true;
                    spread=true;
                }
                if(curr->right && !visited[curr->right])
                {
                    q.push(curr->right);
                    visited[curr->right]=true;
                    spread=true;
                }

                if(parent_check[curr] && !visited[parent_check[curr]])
                {
                    q.push(parent_check[curr]);
                    visited[parent_check[curr]]=true;
                    spread=true;
                }
            }
            if(spread) time++;

        }
        return time;
    }
};