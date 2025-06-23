class Solution {
public:
  int solve(int i, vector<int>& cost, vector<int>& dp) {
    int n = cost.size();
    if (i >= n) return 0;
    // if (dp[i] != -1) return dp[i];

    int one = cost[i] + solve(i + 1, cost, dp);
    int two = cost[i] + solve(i + 2, cost, dp);
    int ans=min(one,two);
    return ans;
}

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n + 1, -1);
    return min(solve(0, cost, dp), solve(1, cost, dp));
}
};



