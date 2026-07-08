class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int initialColor=image[sr][sc];
        if(initialColor==color) return image;
        image[sr][sc]=color;

        queue<pair<int,int>>q;
        q.push({sr,sc});

        int row[]={0,1,0,-1};
        int col[]={1,0,-1,0};

        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nrow=r+row[i];
                int ncol=c+col[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initialColor)
                {
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
    }
};