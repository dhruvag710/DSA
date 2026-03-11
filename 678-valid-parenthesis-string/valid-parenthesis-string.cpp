class Solution {
public:

    bool solve(string &s, int index, int count, vector<vector<int>>& dp)
    {
        if(count < 0) return false;

        if(index == s.size())
            return count == 0;

        if(dp[index][count] != -1)
            return dp[index][count];

        bool ans;

        if(s[index] == '(')
        {
            ans = solve(s, index+1, count+1, dp);
        }
        else if(s[index] == ')')
        {
            ans = solve(s, index+1, count-1, dp);
        }
        else
        {
            ans =
            solve(s, index+1, count+1, dp) || 
            solve(s, index+1, count-1, dp) || 
            solve(s, index+1, count, dp);
        }

        return dp[index][count] = ans;
    }


    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return solve(s, 0, 0, dp);
    }
};