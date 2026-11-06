
class Solution {
public:
    vector<int> countServers(
        int n,
        vector<vector<int>>& logs,
        int x,
        vector<int>& queries
    ) {

        int m = logs.size();
        int k = queries.size();

        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < k; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> ans(k);

        unordered_map<int, int> freq;

        int left = 0;
        int right = 0;

        for (auto [q, index] : sortedQueries) {

            int start = q - x;

            while (right < m && logs[right][1] <= q) {
                freq[logs[right][0]]++;
                right++;
            }

            while (left < right && logs[left][1] < start) {

                int server = logs[left][0];

                freq[server]--;

                if (freq[server] == 0) {
                    freq.erase(server);
                }

                left++;
            }

            ans[index] = n - freq.size();
        }

        return ans;
    }
};
