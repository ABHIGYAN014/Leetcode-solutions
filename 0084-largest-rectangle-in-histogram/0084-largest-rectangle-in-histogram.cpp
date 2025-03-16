class Solution {
public:
    vector<int> PreviousSmaller(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(heights.size());
        for (int i = 0; i < heights.size(); i++) {
            int curr = heights[i];

            while (st.top()!=-1 && heights[st.top()]>=curr) {
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
        vector<int> ans(heights.size());
        for (int i = heights.size()-1; i>=0; i--) {
            int curr = heights[i];

            while (st.top()!=-1 && heights[st.top()]>=curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev = PreviousSmaller(heights);
        vector<int> next = NextSmaller(heights);

        int maxArea=INT_MIN;
        int size=heights.size();
        for(int i=0;i<heights.size();i++)
        {
            if(next[i]==-1)
            {
                next[i]=size;
            }

            int length=heights[i];
            int width=next[i]-prev[i]-1;
            int area=length*width;
            maxArea=max(area,maxArea);
        }
        return maxArea;
    }
};