#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        // Sort the array to use two-pointer approach
        std::sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        
        // Traverse each element as the potential first element in the triplet
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // Update closestSum if currentSum is closer to target
                if (std::abs(currentSum - target) < std::abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                // Adjust pointers based on comparison with target
                if (currentSum < target) {
                    ++left;  // Increase the sum by moving left pointer
                } else if (currentSum > target) {
                    --right;  // Decrease the sum by moving right pointer
                } else {
                    // If we find an exact match
                    return currentSum;
                }
            }
        }
        
        return closestSum;
    }
};
