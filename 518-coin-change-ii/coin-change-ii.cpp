class Solution {
public:
    int change(int amount, vector<int>& coins) {

        vector<unsigned int> dp(amount + 1, 0);
        dp[0] = 1;

        for(int coin : coins)
        {
            for(int sum = coin; sum <= amount; sum++)
            {
                dp[sum] += dp[sum - coin];
            }
        }

        return (int)dp[amount];
    }
};