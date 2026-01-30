class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int mid = n / 2;

        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());

        vector<long long> leftSums;
        vector<long long> rightSums;

        int n1 = left.size();
        for (int mask = 0; mask < (1 << n1); mask++) {
            long long sum = 0;
            for (int i = 0; i < n1; i++) {
                if (mask & (1 << i)) {
                    sum += left[i];
                }
            }
            leftSums.push_back(sum);
        }

        int n2 = right.size();
        for (int mask = 0; mask < (1 << n2); mask++) {
            long long sum = 0;
            for (int i = 0; i < n2; i++) {
                if (mask & (1 << i)) {
                    sum += right[i];
                }
            }
            rightSums.push_back(sum);
        }

        sort(rightSums.begin(), rightSums.end());

        long long ans = llabs(goal);  

        for (long long leftSum : leftSums) {
            long long target = goal - leftSum;

            auto it = lower_bound(rightSums.begin(), rightSums.end(), target);

            if (it != rightSums.end()) {
                ans = min(ans, llabs(leftSum + *it - goal));
            }

            if (it != rightSums.begin()) {
                it--;
                ans = min(ans, llabs(leftSum + *it - goal));
            }
        }

        return ans;
    }
};
