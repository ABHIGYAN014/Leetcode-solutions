class Solution {
public:
    vector<int> PreviousSmaller(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(heights.size());
        for (int i = 0; i < heights.size(); i++) {
            int curr = heights[i];

            while (st.top() != -1 && heights[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> NextSmaller(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(heights.size(), heights.size()); // Initialize with size to avoid -1 handling
        for (int i = heights.size() - 1; i >= 0; i--) {
            int curr = heights[i];

            while (st.top() != -1 && heights[st.top()] >= curr) {
                st.pop();
            }
            if (st.top() != -1) ans[i] = st.top(); // Avoid unnecessary -1 assignments
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev = PreviousSmaller(heights);
        vector<int> next = NextSmaller(heights);

        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int length = heights[i];
            int width = next[i] - prev[i] - 1;
            maxArea = max(maxArea, length * width);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0; 
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};
