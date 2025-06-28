class Solution {
public:
    int solveUsingMem(vector<int>& arr, map<pair<int, int>, int>& maxi, int s,
                      int e, vector<vector<int>>& dp) {
        // base case
        if (s >= e)
            return 0;
        if (dp[s][e] != -1)
            return dp[s][e];
        // ek case
        int ans = INT_MAX;
        for (int i = s; i < e; i++) {
            int leftRangeMax = maxi[{s, i}];
            int rightRangeMax = maxi[{i + 1, e}];
            int nonLeafValue = leftRangeMax * rightRangeMax;
            ans = min(ans, nonLeafValue + solveUsingMem(arr, maxi, s, i, dp) +
                               solveUsingMem(arr, maxi, i + 1, e, dp));
        }
        dp[s][e] = ans;
        return dp[s][e];
    }
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),-1));
        map<pair<int, int>, int> maxi;
        for (int i = 0; i < arr.size(); i++)
            for (int j = i; j < arr.size(); j++)
                if (i == j)
                    maxi[{i, j}] = arr[i];
                else
                    maxi[{i, j}] = max(maxi[{i, j - 1}], arr[j]);
        return solveUsingMem(arr, maxi, 0, arr.size() - 1, dp);
    }
};