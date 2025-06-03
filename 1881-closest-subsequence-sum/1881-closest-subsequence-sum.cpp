class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> leftSums, rightSums;

        solve(nums, 0, n/2, 0, leftSums);
        solve(nums, n/2, n, 0, rightSums);

        sort(rightSums.begin(), rightSums.end());

        int diff = INT_MAX;

        for (int sum : leftSums) {
            int target = goal - sum;
            auto it = lower_bound(rightSums.begin(), rightSums.end(), target);

            if (it != rightSums.end()) {
                diff = min(diff, abs(sum + *it - goal));
            }
            if (it != rightSums.begin()) {
                it--;
                diff = min(diff, abs(sum + *it - goal));
            }
        }

        return diff;
    }

private:
    void solve(vector<int>& nums, int start, int end, int currentSum, vector<int>& sums) {
        if (start == end) {
            sums.push_back(currentSum);
            return;
        }
        solve(nums, start + 1, end, currentSum + nums[start], sums);
        solve(nums, start + 1, end, currentSum, sums);
    }
};
