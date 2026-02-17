class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int t=0; t<=amount; t++)
        {
            if(t % coins[0]==0) dp[0][t]=t/coins[0];
            else dp[0][t]=1e9;
        }
        for(int ind=1;ind<n;ind++){
            for(int t=0;t<=amount;t++)
            {
                int notTake=0+dp[ind-1][t];
                int take=1e9;
                if(coins[ind]<=t){
                    take=1+dp[ind][t-coins[ind]];
                }
                dp[ind][t]=min(take, notTake);
            }
        }

        int ans=dp[n-1][amount];
        if(ans>=1e9) return -1;
        return ans;
    }
};