class Solution {
public:
    void dfs(int srow, int scol, vector<vector<char>>& board)
    {
        int n=board.size();
        int m=board[0].size();

        int row[]={0,1,0,-1};
        int col[]={1,0,-1,0};

        for(int i=0;i<4;i++)
        {
            int nrow=srow+row[i];
            int ncol=scol+col[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O')
            {
                board[nrow][ncol]='A';
                dfs(nrow,ncol,board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O')
            {
                board[0][j]='A';
                dfs(0,j,board);
            }
        }

        for(int j=0;j<m;j++)
        {
            if(board[n-1][j]=='O')
            {
                board[n-1][j]='A';
                dfs(n-1,j,board);
            }
        }

        for(int i=1;i<n-1;i++)
        {
            if(board[i][0]=='O')
            {
                board[i][0]='A';
                dfs(i,0,board);
            }
        }

        for(int i=1;i<n-1;i++)
        {
            if(board[i][m-1]=='O')
            {
                board[i][m-1]='A';
                dfs(i,m-1,board);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='A') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};