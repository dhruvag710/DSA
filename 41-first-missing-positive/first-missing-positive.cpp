
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int ans = 1;
        while (s.count(ans)) {
            ans++;
        }

        return ans;
    }
};
