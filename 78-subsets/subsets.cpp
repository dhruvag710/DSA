class Solution {
public:
    vector<vector<int>> ans;

    void helper(int idx, vector<int>& nums, vector<int>& curr) {
        if (idx == nums.size()) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        helper(idx + 1, nums, curr);

        curr.pop_back();
        helper(idx + 1, nums, curr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        helper(0, nums, curr);
        return ans;
    }
};
