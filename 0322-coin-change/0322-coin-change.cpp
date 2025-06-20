class Solution {
public:
    int solve(vector<int>& coins, int amount,vector<int>&dp) {
        if (amount == 0) {
            return 0;
        }

        if(dp[amount]!=-1)
        {
            return dp[amount];
        }

        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            if (amount - coins[i] >= 0) {
                int temp = solve(coins, amount - coins[i],dp);
                if (temp != INT_MAX) {
                    int ans = 1 + temp;
                    mini = min(mini, ans);
                }
            }
        }
        
            dp[amount]=mini;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {

        int n=coins.size();
        vector<int>dp(amount+1,-1);
        int res = solve(coins, amount,dp);
        return res == INT_MAX ? -1 : res;
    }
};
