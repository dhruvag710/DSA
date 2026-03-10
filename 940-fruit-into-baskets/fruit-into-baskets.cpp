class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>mpp;

        int n=fruits.size();
        int left=0, right=0;
        int ans=0;

        for(right=0;right<n;right++)
        {
            mpp[fruits[right]]++;
            while(mpp.size()>2)
            {
                mpp[fruits[left]]--;

                if(mpp[fruits[left]]==0)
                {
                    mpp.erase(fruits[left]);
                }

                left++;
            }
            ans=max(ans, right-left+1);
        }
        return ans;
    }
};