class Solution {
public:
    int solve(string&text1, string&text2, int i, int j,vector<vector<int>>& dp) {
        if (i >= text1.length())
            return 0;
        if (j >= text2.length())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int same = 0;
        int diff = 0;
        if (text1[i] == text2[j]) {
            same = 1 + solve(text1, text2, i + 1, j + 1, dp);
        } else {
            diff = 0 + max(solve(text1, text2, i + 1, j, dp),
                           solve(text1, text2, i, j + 1, dp));
        }
        int final = max(same, diff);
        dp[i][j] = final;
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        int ans = solve(text1, text2, i, j, dp);
        return ans;
    }
};