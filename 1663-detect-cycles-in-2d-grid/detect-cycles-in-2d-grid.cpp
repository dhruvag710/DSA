class Solution {
public:
    bool dfs(int sr, int sc, int pr, int pc, vector<vector<char>>& grid, vector<vector<int>>& vis)
    {
        int n=grid.size();
        int m=grid[0].size();

        int row[]={0,1,0,-1};
        int col[]={1,0,-1,0};

        vis[sr][sc]=1;

        for(int i=0;i<4;i++)
        {
            int nr=sr+row[i];
            int nc=sc+col[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==grid[sr][sc])
            {
                if(!vis[nr][nc])
                {
                    if(dfs(nr,nc,sr,sc,grid,vis)) return true;
                }
                else if(!(nr==pr && nc==pc)) return true;
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
                    if(dfs(i,j,-1,-1,grid,vis)) return true;
                }
            }
        }
        return false;
    }
};