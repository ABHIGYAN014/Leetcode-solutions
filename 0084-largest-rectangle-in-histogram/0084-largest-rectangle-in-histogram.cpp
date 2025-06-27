class Solution {
public:

  // Finding the index of all elements smaller than thaat particular   element  in left of it  for eg sample 1 : [-1,-1,1,2,1,4]
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
 // Finding the index of all elements smaller than thaat particular   element in right of it for eg sample 1 : [1,-1,4,4,-1,-1]
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