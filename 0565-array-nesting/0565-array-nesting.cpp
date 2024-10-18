class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxLength = 0;
        int n = nums.size();
        vector<bool> visited(n, false);  // Track visited elements

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int start = nums[i];
                int count = 0;

                // Traverse the cycle starting from nums[i]
                while (!visited[start]) {
                    visited[start] = true;
                    start = nums[start];
                    ++count;
                }
                maxLength = max(maxLength, count);  // Update maximum length
            }
        }
        return maxLength; 
    }
};