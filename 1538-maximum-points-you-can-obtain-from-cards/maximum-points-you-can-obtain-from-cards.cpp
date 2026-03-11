class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int left=0, right=n-k;

        if(n==0 || k==0) return 0;
        if(n==1) return cardPoints[0];
        int sum=0;
        for(int i=0; i<n-k; i++)
        {
            sum+=cardPoints[i];
        }
        int ans=sum;
        int totalSum=0;
        for(int i=0;i<n;i++)
        {
            totalSum+=cardPoints[i];
        }

        for(right; right<n; right++)
        {
           sum+=cardPoints[right];
           
           sum-=cardPoints[left];
           left++;
           ans=min(ans, sum);

        }
        return totalSum-ans;
    }
};