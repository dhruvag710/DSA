class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();

        for(int i = 0; i < n; i++) {
            if(st.empty()) {
                st.push(asteroids[i]);
            }
            else {
                if(asteroids[i] > 0 || st.top() < 0) {
                    st.push(asteroids[i]);
                }
                else {
                    // Collision happens
                    while(!st.empty() && st.top() > 0 && abs(st.top()) < abs(asteroids[i])) {
                        st.pop();
                    }

                    if(!st.empty() && st.top() > 0 && abs(st.top()) == abs(asteroids[i])) {
                        st.pop();
                        // both destroyed, do not push current
                    }
                    else if(st.empty() || st.top() < 0) {
                        st.push(asteroids[i]);
                    }
                    // else if st.top() > abs(asteroids[i]) → do nothing, current destroyed
                }
            }
        }

        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
