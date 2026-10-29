#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, LOG, timer;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, fenwick, pref;

    void dfs(int root, const string& s) {
        timer = 0;

        stack<tuple<int, int, int>> st;
        st.push({root, root, 0});

        while (!st.empty()) {
            auto [u, p, state] = st.top();
            st.pop();

            if (state == 1) {
                tout[u] = timer;
                continue;
            }

            tin[u] = ++timer;

            up[0][u] = p;
            for (int j = 1; j < LOG; j++) {
                up[j][u] = up[j - 1][up[j - 1][u]];
            }

            if (u == root) {
                pref[u] = 1 << (s[u] - 'a');
            } else {
                pref[u] = pref[p] ^ (1 << (s[u] - 'a'));
            }

            st.push({u, p, 1});

            for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
                int v = adj[u][i];

                if (v == p) continue;

                depth[v] = depth[u] + 1;
                st.push({v, u, 0});
            }
        }
    }

    void updateBIT(int i, int val) {
        for (; i <= n; i += i & -i) {
            fenwick[i] ^= val;
        }
    }

    void rangeXor(int l, int r, int val) {
        updateBIT(l, val);

        if (r + 1 <= n) {
            updateBIT(r + 1, val);
        }
    }

    int pointQuery(int i) {
        int res = 0;

        for (; i > 0; i -= i & -i) {
            res ^= fenwick[i];
        }

        return res;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                u = up[j][u];
            }
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return up[0][u];
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        this->n = n;
        LOG = 1;

        while ((1LL << LOG) <= n) {
            LOG++;
        }

        timer = 0;
        adj.assign(n, {});
        up.assign(LOG, vector<int>(n, 0));
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        pref.assign(n, 0);
        fenwick.assign(n + 2, 0);

        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, s);

        for (int u = 0; u < n; u++) {
            rangeXor(tin[u], tin[u], pref[u]);
        }

        vector<bool> ans;
        ans.reserve(queries.size());

        for (const string& q : queries) {
            stringstream ss(q);

            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');
                int delta = oldMask ^ newMask;

                if (delta != 0) {
                    rangeXor(tin[u], tout[u], delta);
                    s[u] = c;
                }
            } else {
                int v;
                ss >> v;

                int pu = pointQuery(tin[u]);
                int pv = pointQuery(tin[v]);

                int ancestor = lca(u, v);
                int pathMask =
                    pu ^ pv ^ (1 << (s[ancestor] - 'a'));

                ans.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return ans;
    }
};