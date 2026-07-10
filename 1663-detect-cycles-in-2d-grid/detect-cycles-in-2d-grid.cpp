class Solution {
public:
    bool detectCycle(int sr, int sc, vector<vector<char>>&grid, vector<vector<int>>& vis)
    {
        int n=grid.size();
        int m=grid[0].size();
        int row[]={0,1,0,-1};
        int col[]={1,0,-1,0};

        queue<pair<pair<int,int>,pair<int,int>>>q;
        q.push({{sr,sc},{-1,-1}});
        vis[sr][sc]=1;
        while(!q.empty())
        {
            int sr=q.front().first.first;
            int sc=q.front().first.second;
            int pr=q.front().second.first;
            int pc=q.front().second.second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nr=sr+row[i];
                int nc=sc+col[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==grid[sr][sc])
                {
                    if(!vis[nr][nc])
                    {
                        vis[nr][nc]=1;
                        q.push({{nr,nc},{sr,sc}});
                    }
                    else if(!(nr==pr && nc==pc)) return true;
                }
            }
        }
        return false;

    }




    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j])
                {
                    if(detectCycle(i,j,grid,vis)) return true;
                }
            }
        }
        return false;
    }
};