class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        vector<string>words;
        int i=0;
        while(i<n)
        {
            while(i<n && s[i]==' ') i++;
            if(i>=n) break;
            int start=i;
            while(i<n && s[i]!=' ') i++;
            int end=i;

            words.push_back(s.substr(start,end-start));
        }
        reverse(words.begin(),words.end());
        string result;
        for(int j=0;j<words.size();j++)
        {
            result+=words[j];
            if(j!=words.size()-1) result+=' ';
        }
        return result;
    }
};