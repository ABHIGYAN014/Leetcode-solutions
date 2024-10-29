class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;                       // Left pointer
        int right = height.size() - 1;      // Right pointer
        int max_area = 0;                   // Store the maximum area

        while (left < right) {
            // Calculate the area with the current two lines
            int area = min(height[left], height[right]) * (right - left);
            max_area = max(max_area, area);

            // Move the pointer corresponding to the shorter line
            if (height[left] < height[right]) {
                left++;  // Move the left pointer to the right
            } else {
                right--; // Move the right pointer to the left
            }
        }
        return max_area;
    }
};
