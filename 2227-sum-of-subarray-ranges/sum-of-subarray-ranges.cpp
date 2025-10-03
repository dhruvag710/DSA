class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {
        stack<int> s;
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);

        for(int i=0; i<n; i++) {
            while(!s.empty() && arr[i] < arr[s.top()]) s.pop();
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while(!s.empty()) s.pop();

        for(int i=n-1; i>=0; i--) {
            while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        long long ans = 0;
        for(int i=0; i<n; i++) {
            ans += 1ll * arr[i] * (i - left[i]) * (right[i] - i);
        }
        return ans;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        stack<int> s;
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);

        for(int i=0; i<n; i++) {
            while(!s.empty() && arr[i] > arr[s.top()]) s.pop();
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while(!s.empty()) s.pop();

        for(int i=n-1; i>=0; i--) {
            while(!s.empty() && arr[s.top()] <= arr[i]) s.pop();
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        long long ans = 0;
        for(int i=0; i<n; i++) {
            ans += 1ll * arr[i] * (i - left[i]) * (right[i] - i);
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long minSum = sumSubarrayMins(nums);
        long long maxSum = sumSubarrayMaxs(nums);
        return maxSum - minSum;
    }
};
