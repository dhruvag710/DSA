class Solution {
public:
    vector<string> ans;

    void helper(string curr, int open, int close, int n) {
        
        if (open == n && close == n) {
            ans.push_back(curr);
            return;
        }

        if (open < n) {
            helper(curr + "(", open + 1, close, n);
        }

        if (close < open) {
            helper(curr + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        helper("", 0, 0, n);
        return ans;
    }
};
