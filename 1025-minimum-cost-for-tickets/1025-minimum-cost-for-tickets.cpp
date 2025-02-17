class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days.back(); // Last day of travel
        int firstDay = days.front(); // First day of travel
        unordered_set<int> travelDays(days.begin(), days.end()); // To check travel days quickly

        vector<int> dp(lastDay + 1, 0); // DP array

        for (int i = firstDay; i <= lastDay; ++i) {
            if (travelDays.count(i) == 0) {
                dp[i] = dp[i - 1]; // No cost if it's not a travel day
            } else {
                int cost1 = dp[i - 1] + costs[0]; // 1-day pass
                int cost7 = dp[max(0, i - 7)] + costs[1]; // 7-day pass
                int cost30 = dp[max(0, i - 30)] + costs[2]; // 30-day pass
                dp[i] = min({cost1, cost7, cost30});
            }
        }

        return dp[lastDay]; // Minimum cost to cover all travel days
    }
};
