class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            {
                q.push({i,0});
                board[i][0]='N';
            }
            if(board[i][m-1]=='O')
            {
                q.push({i,m-1});
                board[i][m-1]='N';
            }// N means we cannot capture it
        }

        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O')
            {
                q.push({0,j});
                board[0][j]='N';
            }
            if(board[n-1][j]=='O')
            {
                q.push({n-1,j});
                board[n-1][j]='N';
            }
        }


        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();


            if(i-1>=0 && board[i-1][j]=='O')
            {
                board[i-1][j]='N';
                q.push({i-1,j});
            }

            if(j-1>=0 && board[i][j-1]=='O')
            {
                board[i][j-1]='N';
                q.push({i,j-1});
            }

            if(i+1<n && board[i+1][j]=='O')
            {
                board[i+1][j]='N';
                q.push({i+1,j});
            }

            if(j+1<m && board[i][j+1]=='O')
            {
                board[i][j+1]='N';
                q.push({i,j+1});
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='N') board[i][j]='O';
                else board[i][j]='X';
            }
        }
    }
};