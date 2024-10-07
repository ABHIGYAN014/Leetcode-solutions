class Solution {
public:
    int rob(vector<int>& nums) {
         if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        
        // Initialize two variables to store the maximum money we can rob
        int prev1 = 0; // Maximum money robbed till the previous house
        int prev2 = 0; // Maximum money robbed till the house before the previous house
        
        for (int num : nums) {
            int current = std::max(prev1, prev2 + num); // Current maximum money that can be robbed
            prev2 = prev1; // Move prev1 to prev2
            prev1 = current; // Update prev1 to current
        }
        
        return prev1; // 
    }
};