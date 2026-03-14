class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int>ahead(n+1,0), cur(n+1,0);

        for(int curr = n-1; curr >= 0; curr--)
        {
            for(int prev = curr-1; prev >= -1; prev--)
            {
                int take = 0;

                if(prev == -1 || nums[curr] > nums[prev])
                {
                    take = 1 + ahead[curr+1];
                }

                int notTake = ahead[prev+1];

                cur[prev+1] = max(take, notTake);
            }
            ahead=cur;
        }

        return ahead[0];
    }
};