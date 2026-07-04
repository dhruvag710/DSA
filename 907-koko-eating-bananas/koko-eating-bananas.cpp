class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high = *max_element(piles.begin(), piles.end());

        while(low<=high)
        {
            long long hours=0;
            int mid=(low+high)/2;
            for(int i=0;i<n;i++)
            {
                if(piles[i]%mid==0) hours+=piles[i]/mid;
                else hours+=piles[i]/mid+1;
            }
            if(hours>h) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};