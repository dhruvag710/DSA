class Solution {
public:

    int validSub(int mid,  vector<int>& nums)
    {
        int stu=1;
        int n=nums.size();
        int sum=0;
        int i=0;
        for(int i=0;i<n;i++)
        {
            if(sum+nums[i]<=mid) sum+=nums[i];
            else stu++, sum=nums[i];
        }
        return stu;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int count=validSub(mid,nums);
            if(count<=k) ans=mid, high=mid-1;
            else low=mid+1;
        }
        return ans;
    }
};