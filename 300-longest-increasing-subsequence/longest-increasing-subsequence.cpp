class Solution {
public:
    int solve(vector<int>& nums, int n, vector<vector<int>>& dp, int prev, int curr)
    {
        if(curr==n) return 0;
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];

        int take=0;
        if(prev==-1 || nums[curr]>nums[prev])
        {
            take=1+solve(nums, n, dp, curr, curr+1);
        }

        int notTake=solve(nums, n, dp, prev, curr+1);

        return dp[curr][prev+1]= max(take,notTake);
    }


    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1,-1));
        return solve(nums, n, dp, -1, 0);
    }
};