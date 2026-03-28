class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent)
    {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* current=q.front();
            q.pop();
            if(current->left)
            {
                parent[current->left]=current;
                q.push(current->left);
            }
            if(current->right)
            {
                parent[current->right]=current;
                q.push(current->right);
            }
        }


    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);


        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);

        visited[target]=true;
        int curr_level=0;

        while(!q.empty())
        {
            int size=q.size();
            if(curr_level==k) break;
            for(int i=0;i<size;i++){
                TreeNode* current=q.front();
                q.pop();

                if(current->left && !visited[current->left])
                {
                    q.push(current->left);
                    visited[current->left]=true;
                }

                if(current->right && !visited[current->right])
                {
                    q.push(current->right);
                    visited[current->right]=true;
                }
                if(parent[current] && !visited[parent[current]])
                {
                    q.push(parent[current]);
                    visited[parent[current]]=true;
                }
            }
            curr_level++;
        }

        vector<int>result;
        while(!q.empty())
        {
            TreeNode* current=q.front();
            q.pop();
            result.push_back(current->val);
        }
        return result;

    }
};