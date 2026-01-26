class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> prev(n,0),curr(n,0);
        
        for(int j=0;j<n;j++) prev[j]=matrix[n-1][j];
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                int d=matrix[i][j] + prev[j];
                int dr=INT_MAX, dl=INT_MAX;
                if(j<n-1) dr=matrix[i][j]+prev[j+1];
                if(j>0) dl=matrix[i][j]+prev[j-1];

                 curr[j]=min(d,min(dr,dl));
            }
            prev=curr;
        }
        return *min_element(prev.begin(), prev.end());

        
    }
};