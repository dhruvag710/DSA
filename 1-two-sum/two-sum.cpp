class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> m;  

        for (int i = 0; i < n; i++) {
            int need = target - nums[i];
            if (m.find(need) != m.end()) {
                return {m[need], i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};