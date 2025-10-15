class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0;
        long long sum=0;
        int ans=0;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];

            long long cost= 1ll*nums[i]*(i-l+1)-sum;

            if(cost>k)
            {
                sum-=nums[l];
                l++;
                cost=1ll*nums[i]*(i-l+1)-sum;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};