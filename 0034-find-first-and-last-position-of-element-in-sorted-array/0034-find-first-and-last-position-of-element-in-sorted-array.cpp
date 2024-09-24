class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);  // Initialize result with [-1, -1]
        int left = 0, right = nums.size() - 1;
        
        // First binary search to find the first occurrence
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                result[0] = mid; // Tentative first occurrence
                right = mid - 1; // Look left to find earlier occurrence
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // Reset left and right pointers for second search
        left = 0;
        right = nums.size() - 1;
        
        // Second binary search to find the last occurrence
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                result[1] = mid; // Tentative last occurrence
                left = mid + 1;  // Look right to find later occurrence
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};
