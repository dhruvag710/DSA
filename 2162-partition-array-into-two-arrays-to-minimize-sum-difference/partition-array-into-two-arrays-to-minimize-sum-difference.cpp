class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;

        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());

        long long totalSum = 0;
        for (int x : nums) totalSum += x;

        vector<vector<int>> leftSums(mid + 1), rightSums(mid + 1);

        for (int i = 0; i <= mid; i++) {
            leftSums[i].reserve(1 << mid);
            rightSums[i].reserve(1 << mid);
        }

        for (int mask = 0; mask < (1 << mid); mask++) {
            int s = 0, cnt = 0;
            for (int i = 0; i < mid; i++) {
                if (mask & (1 << i)) {
                    s += left[i];
                    cnt++;
                }
            }
            leftSums[cnt].push_back(s);
        }

        for (int mask = 0; mask < (1 << mid); mask++) {
            int s = 0, cnt = 0;
            for (int i = 0; i < mid; i++) {
                if (mask & (1 << i)) {
                    s += right[i];
                    cnt++;
                }
            }
            rightSums[cnt].push_back(s);
        }

        for (int i = 0; i <= mid; i++) {
            sort(leftSums[i].begin(), leftSums[i].end());
            sort(rightSums[i].begin(), rightSums[i].end());
        }

        long long ans = LLONG_MAX;

        for (int k = 0; k <= mid; k++) {
            auto &rs = rightSums[mid - k];
            for (int ls : leftSums[k]) {
                int target = (int)(totalSum / 2 - ls);

                auto it = lower_bound(rs.begin(), rs.end(), target);

                if (it != rs.end())
                    ans = min(ans, llabs(totalSum - 2LL * (ls + *it)));

                if (it != rs.begin()) {
                    --it;
                    ans = min(ans, llabs(totalSum - 2LL * (ls + *it)));
                }

                if (ans == 0) return 0; 
            }
        }

        return (int)ans;
    }
};
