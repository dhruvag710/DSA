class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalSum=0;
        for(int x:nums) totalSum+=x;
        if(totalSum< abs(target) || (totalSum+target)%2) return 0;
        int sum=(totalSum+target)/2;


        vector<int>prev(sum+1,0), curr(sum+1,0);

        if(nums[0] == 0)
    prev[0] = 2;
else
    prev[0] = 1;

        if(nums[0]!=0 && nums[0]<=sum) prev[nums[0]]=1;

        for(int i=1;i<n;i++)
        {
            for(int s=0;s<=sum;s++)
            {
                int notTake=prev[s];
                int take=0;
                if(nums[i]<=s)
                {
                    take=prev[s-nums[i]];
                }
                curr[s]=take+notTake;
            }
            prev=curr;
        }
    return prev[sum];
        
    }
};