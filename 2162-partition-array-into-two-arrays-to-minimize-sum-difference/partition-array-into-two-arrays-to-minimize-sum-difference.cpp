static const auto fast_io = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        int mid=n/2;
        vector<int> left(nums.begin(), nums.begin()+mid);
        vector<int> right(nums.begin()+mid, nums.end());
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        
        vector<vector<int>> leftSums(mid+1), rightSums(mid+1);

        for(int mask=0; mask<(1<<mid); mask++)
        {
            long long ans=0;
             int count=0;
            for(int i=0;i<mid;i++)
            {
                if(mask & (1<<i)) ans+=left[i], count++;
                
            }
            leftSums[count].push_back(ans);
        }

        for(int mask=0; mask<(1<<mid); mask++)
        {
            long long ans=0;
             int count=0;
            for(int i=0;i<mid;i++)
            {
                if(mask & (1<<i)) ans+=right[i],count++;
                
            }
            rightSums[count].push_back(ans);
        }

        for (int i = 0; i <= mid; i++) {
    sort(leftSums[i].begin(), leftSums[i].end());
    sort(rightSums[i].begin(), rightSums[i].end());
}


        long long ans=INT_MAX;

        for(int k=0;k<=mid;k++)
        {
            for(int ls: leftSums[k])
            {
                int reqd=(sum/2)-ls;

                auto it=lower_bound(rightSums[mid-k].begin(), rightSums[mid-k].end(), reqd);
                if(it!=rightSums[mid-k].end())
                {
                    ans=min(ans, llabs(sum- 2*(*it+ls)));
                }

                if(it!=rightSums[mid-k].begin())
                {
                    it--;
                    ans=min(ans, llabs(sum- 2*(*it+ls)));
                }
            }
        }       
        return ans;
    }
};