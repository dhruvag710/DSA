class Solution {
public:
    void dfs(vector<int> adj[], int node, vector<int>& vis)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(adj, it, vis);
            }
        }
    }



    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adj[n];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int>vis(n,0);
        int count=0;

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(adj,i,vis);
            }
        }
        return count;
    }
};