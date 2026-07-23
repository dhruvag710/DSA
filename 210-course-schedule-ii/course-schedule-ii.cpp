class Solution {
public:
    bool isCycle(int src, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& recPath,stack<int>& st) {
        vis[src] = true;
        recPath[src] = true;

        for (int neigh : adj[src]) {
            if (!vis[neigh]) {
                if (isCycle(neigh, adj, vis,recPath, st))
                    return true;
            }
            else if (recPath[neigh]) {
                return true;
            }
        }
        st.push(src);
        recPath[src] = false;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto &edge : prerequisites) {
            int course = edge[0];
            int prereq = edge[1];

            adj[prereq].push_back(course);
        }
        stack<int>st;
        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (isCycle(i, adj, vis, recPath,st))
                    return {};  
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;   
    }
};