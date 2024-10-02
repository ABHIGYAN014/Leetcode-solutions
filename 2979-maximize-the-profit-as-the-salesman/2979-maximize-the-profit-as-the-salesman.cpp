class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        // Sort offers based on their end time
        sort(offers.begin(), offers.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Compare by end time
        });
        
        // dp[i] will store the maximum profit achievable up to the i-th offer
        vector<int> dp(offers.size(), 0);
        
        // Helper function to find the previous non-overlapping offer using binary search
        auto findPrevious = [&](int index) -> int {
            int low = 0, high = index - 1, result = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (offers[mid][1] < offers[index][0]) { // Check non-overlap condition
                    result = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            return result;
        };
        
        // Loop through each offer and calculate maximum profit
        for (int i = 0; i < offers.size(); ++i) {
            int takeProfit = offers[i][2]; // Profit of taking current offer
            int prev = findPrevious(i);    // Find previous non-overlapping offer
            if (prev != -1) {
                takeProfit += dp[prev];    // Add profit from previous non-overlapping offer
            }
            int skipProfit = (i > 0) ? dp[i - 1] : 0; // Profit of skipping current offer
            dp[i] = max(takeProfit, skipProfit);      // Choose the option with maximum profit
        }
        
        return dp.back(); // Maximum profit is the last element of dp
    }
};
