#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        
        // Sort the array to facilitate the two-pointer approach and avoid duplicates
        std::sort(nums.begin(), nums.end());
        
        // First two loops to fix the first and second numbers
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for the first number
            
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicates for the second number
                
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;
                        
                        // Move pointers to skip duplicates
                        while (left < right && nums[left] == nums[left - 1]) ++left;
                        while (left < right && nums[right] == nums[right + 1]) --right;
                    }
                    else if (sum < target) {
                        ++left;
                    }
                    else {
                        --right;
                    }
                }
            }
        }
        
        return result;
    }
};
