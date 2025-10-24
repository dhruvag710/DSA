class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0, zeroCount=0,maxlen=0;
        int n=nums.size();

        for(int j=0;j<n;j++)
        {
            if(nums[j]==0) zeroCount++;

            while(zeroCount>k)
            {
                if(nums[i]==0) zeroCount--;
                i++;
            }
            maxlen=max(maxlen,j-i+1);
        }
        return maxlen;
    }
};