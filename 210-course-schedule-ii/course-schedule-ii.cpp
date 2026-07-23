class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>inDegree(n,0);

        for(auto &edge: edges)
        {
            int course=edge[0];
            int preReq=edge[1];

            adj[preReq].push_back(course);
            inDegree[course]++;
        }

        queue<int>q;

        for(int i=0;i<n;i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
            }

        }

        vector<int>ans;

        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            ans.push_back(node);
            for(int neigh:adj[node])
            {
                inDegree[neigh]--;
                if(inDegree[neigh]==0)
            {
                q.push(neigh);
            }
            }

            
        }

        if(ans.size()==n) return ans;

        return {};
    }
};