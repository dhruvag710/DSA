class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>s;
        const int MOD = 1e9+7;
        int n=arr.size();
        vector<int>leftmin(n,-1);
        vector<int>rightmin(n,-1);

        for(int i=0;i<n;i++)
        {
           while(!s.empty() && arr[i]<arr[s.top()])
           {
            s.pop();
           }
          if(s.empty()) leftmin[i] = -1;
    else leftmin[i] = s.top();
    s.push(i);
        }
        while(!s.empty()) s.pop(); // clear stack

for(int i=n-1; i>=0; i--) {
    while(!s.empty() && arr[s.top()] >= arr[i]) {
        s.pop();
    }
    if(s.empty()) rightmin[i] = n;
    else rightmin[i] = s.top();
    s.push(i);
}

    long long ans=0;
    for(int i=0;i<n;i++)
    {
        long long left=i-leftmin[i];
        long long right=rightmin[i]-i;
        long long contri=(1ll*arr[i]*left%MOD*right%MOD)%MOD;
        ans=(ans+contri)%MOD;
    }
    return ans;
    }
};