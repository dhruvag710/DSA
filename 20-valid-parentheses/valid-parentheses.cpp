class Solution {
public:
    bool isValid(string s) {
        vector<char> st;  
        for(auto ch : s) {
            if(ch == '(' || ch == '[' || ch == '{') {
                st.push_back(ch);  
            } else {
                if(st.empty()) return false;
                char top = st.back();  
                if((ch == ')' && top == '(') ||
                   (ch == ']' && top == '[') ||
                   (ch == '}' && top == '{')) {
                    st.pop_back();   // pop
                } else {
                    return false;
                }
            }
        }
        return st.empty();  
    }
};
