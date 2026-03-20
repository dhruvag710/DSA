class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // col -> row -> sorted values
        map<int, map<int, multiset<int>>> nodes;

        // queue: node + (row, col)
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}});

        // BFS traversal
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();

            TreeNode* node = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;

            nodes[col][row].insert(node->val);

            if(node->left)
                q.push({node->left, {row+1, col-1}});

            if(node->right)
                q.push({node->right, {row+1, col+1}});
        }

        // build answer
        vector<vector<int>> ans;

        for(auto p : nodes) {
            vector<int> colNodes;

            for(auto q : p.second) {
                colNodes.insert(colNodes.end(), q.second.begin(), q.second.end());
            }

            ans.push_back(colNodes);
        }

        return ans;
    }
};