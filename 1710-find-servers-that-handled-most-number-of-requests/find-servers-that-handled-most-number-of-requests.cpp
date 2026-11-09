
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival,
                               vector<int>& load) {

        int n = arrival.size();

        // Available servers, sorted by server ID
        set<int> available;

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // Busy servers: {finishTime, serverID}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> busy;

        // Number of requests handled by each server
        vector<int> count(k, 0);

        for (int i = 0; i < n; i++) {

            // Release servers that have finished their requests
            while (!busy.empty() && busy.top().first <= arrival[i]) {

                int server = busy.top().second;
                busy.pop();

                available.insert(server);
            }

            // If all servers are busy, drop this request
            if (available.empty()) {
                continue;
            }

            // Preferred server for this request
            int preferred = i % k;

            // Find the next available server
            auto it = available.lower_bound(preferred);

            // Wrap around if necessary
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            available.erase(it);

            count[server]++;

            busy.push({arrival[i] + load[i], server});
        }

        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
