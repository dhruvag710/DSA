class Solution {
public:
    vector<string> mapping = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string &digits, int index, string &current,
                   vector<string> &ans) {
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char ch : letters) {
            current.push_back(ch);
            backtrack(digits, index + 1, current, ans);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> ans;
        string current;

        backtrack(digits, 0, current, ans);

        return ans;
    }
};