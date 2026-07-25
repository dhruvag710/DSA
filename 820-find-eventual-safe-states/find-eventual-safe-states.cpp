class Solution {
public:
    bool dfs(int src, vector<int>& vis, vector<int>& pathVis,vector<int>& check, vector<vector<int>>& edges)
    {
        vis[src]=1;
        pathVis[src]=1;

        for(auto it:edges[src])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,pathVis,check,edges))
                return true;
            }
            else if(pathVis[it]==1) return true;
            else if(check[it]==0) return true;
        }
        pathVis[src] = 0;
        check[src]=1;
return false;

    }




    vector<int> eventualSafeNodes(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        vector<int> check(n, 0);

        stack<int>st;

        for(int i=0;i<n;i++)
        {
            dfs(i,vis,pathVis,check,edges);
        }
        vector<int> ans;

for(int i = 0; i < n; i++)
{
    if(check[i])
        ans.push_back(i);
}

return ans;
    }
};