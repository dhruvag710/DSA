class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int ans=0, left=0, right=0, maxFreq=0;
        map<char,int>mpp;

        for(int right=0;right<n;right++)
        {
            mpp[s[right]]++;
            maxFreq=max(maxFreq, mpp[s[right]]);

            while(right-left+1-maxFreq >k)
            {
                mpp[s[left]]--;
                if(mpp[s[left]]==0) mpp.erase(s[left]);

                left++;
            }
            ans=max(ans, right-left+1);
        }
        return ans;


    }
};