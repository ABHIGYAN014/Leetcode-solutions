class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;

        // Phase 1: Find the candidate
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == candidate) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    candidate = nums[i];
                    count = 1;
                }
            }
        }

        // Phase 2: Verify the candidate (optional, if you need to ensure it's the majority)
        count = 0;
        for (int num : nums) {
            if (num == candidate) {
                count++;
            }
        }

        // Since the problem guarantees that a majority element exists, 
        // we return the candidate directly without additional checks.
        return candidate;
    }
};
