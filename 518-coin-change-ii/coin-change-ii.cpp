class Solution {
public:

    int solve(int amount, vector<int> &coins, vector<vector<int>> &dp, int index)
    {
        if(index == 0)
        {
            if(amount % coins[0] == 0) return 1;
            return 0;
        }

        if(dp[index][amount] != -1)
            return dp[index][amount];

        int notTake = solve(amount, coins, dp, index-1);

        int take = 0;
        if(coins[index] <= amount)
            take = solve(amount - coins[index], coins, dp, index);

        return dp[index][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        return solve(amount, coins, dp, n-1);
    }
};