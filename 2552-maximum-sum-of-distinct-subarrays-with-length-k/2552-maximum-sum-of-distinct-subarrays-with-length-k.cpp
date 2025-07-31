class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long currSum = 0, MaxSum = 0;
        unordered_map<int, int> freq;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;
            currSum += nums[right];

            while (freq[nums[right]] > 1) {
                freq[nums[left]]--;
                currSum -= nums[left];
                left++;
            }
            if (right - left + 1 == k) {
                MaxSum = max(MaxSum, currSum);
                freq[nums[left]]--;
                currSum -= nums[left];
                left++;
            }
        }
        return MaxSum;
    }
};