class Solution {
public:
    int solveUsingMem(vector<vector<char>>& matrix, int i, int j, int &maxi,vector<vector<int>> &dp )
    {
        if(i>=matrix.size() || j>=matrix[0].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int right=solveUsingMem(matrix,i,j+1,maxi,dp);
        int left=solveUsingMem(matrix, i+1,j,maxi,dp);
        int down=solveUsingMem(matrix, i+1,j+1,maxi,dp);

        if(matrix[i][j]=='1')
        {
            dp[i][j]=1+min(right,min(left,down));
            maxi=max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else return dp[i][j]=0;


    }




    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=0;
        vector<vector<int>> dp(n, vector<int>(m,-1));
        solveUsingMem(matrix, 0,0,maxi,dp);
        return maxi*maxi;
    }
};