class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(auto ch:s)
        {
            if(ch=='(' || ch=='[' || ch=='{') st.push(ch);
            else
            {
                if(st.empty()) return false;
                char cha=st.top();
                if(ch==')' && cha=='(') st.pop();
                else if(ch==']' && cha=='[') st.pop();
                else if(ch=='}' && cha=='{') st.pop();
                else return false;
            }
        }
        return (st.empty());
    }
};