class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
            {
                q.push({i,0});
                grid[i][0]=0;
            }
            if(grid[i][m-1]==1)
            {
                q.push({i,m-1});
                grid[i][m-1]=0;
            }
        }

        for(int j=0;j<m;j++)
        {
            if(grid[0][j]==1)
            {
                q.push({0,j});
                grid[0][j]=0;
            }
            if(grid[n-1][j]==1)
            {
                q.push({n-1,j});
                grid[n-1][j]=0;
            }
        }


        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            if(i-1>=0 && grid[i-1][j]==1)
            {
                q.push({i-1,j});
                grid[i-1][j]=0;
            }

            if(j-1>=0 && grid[i][j-1]==1)
            {
                q.push({i,j-1});
                grid[i][j-1]=0;
            }

            if(i+1<n && grid[i+1][j]==1)
            {
                q.push({i+1,j});
                grid[i+1][j]=0;
            }

            if(j+1<m && grid[i][j+1]==1)
            {
                q.push({i,j+1});
                grid[i][j+1]=0;
            }
        }

        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) count++;
            }
        }

        return count;
    }
};