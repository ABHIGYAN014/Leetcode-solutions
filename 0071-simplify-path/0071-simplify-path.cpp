class Solution {
public:
    void reverseans(stack<string>& st, string& ans) { 
        if (st.empty()) {
            return;
        }
        string minpath = st.top();
        st.pop();
        reverseans(st, ans);
        ans += minpath; 
    }

    string simplifyPath(string path) {
        stack<string> st;
        int i = 0;

        while (i < path.size()) {
            int start = i;
            int end = i + 1;

            while (end < path.size() && path[end] != '/') {
                end++;
            }

            string minpath = path.substr(start, end - start);

            if (minpath == "/" || minpath == "/.") { 
                i = end;
                continue;
            }
            
            if (minpath != "/..") {
                st.push(minpath); 
            } else if (!st.empty()) {
                st.pop();
            }

            i = end;
        }

        string ans = st.empty() ? "/" : "";
        reverseans(st, ans); 
        return ans;
    }
};
