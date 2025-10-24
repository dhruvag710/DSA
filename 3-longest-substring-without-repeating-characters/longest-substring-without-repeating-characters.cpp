class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>freq;
        int i=0,j=0,maxlen=0;
        int n=s.size();

        while(j<n)
        {
            freq[s[j]]++;

            while(freq[s[j]]>1)
            {
                freq[s[i]]--;
                i++;
            }
            maxlen=max(maxlen, j-i+1);
            j++;
        }
        return maxlen;
        
    }
};