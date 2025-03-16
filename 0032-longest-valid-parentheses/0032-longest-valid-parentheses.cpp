class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int maxlength=0;
        st.push(-1);
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '(') {
                st.push(i);
            }
            else {
                st.pop();
                if (!st.empty()) {
                    int length = i - st.top();
                    maxlength = max(length, maxlength);
                }
                 else {
                st.push(i);
            }
            }
        }
        return maxlength;
    }
    
};