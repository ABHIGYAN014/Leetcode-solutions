class Solution {
public:

    bool check(vector<int>& a, vector<int>& b) {
        return a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2];
    }

    int solve(vector<vector<int>>& cuboids, int prev, int curr, vector<vector<int>>& dp) {
        if (curr == cuboids.size())
            return 0;

        if (dp[prev + 1][curr] != -1)
            return dp[prev + 1][curr];

        int include = 0;
        if (prev == -1 || check(cuboids[prev], cuboids[curr])) {
            include = cuboids[curr][2] + solve(cuboids, curr, curr + 1, dp);
        }

        int exclude = solve(cuboids, prev, curr + 1, dp);

        return dp[prev + 1][curr] = max(include, exclude);
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }

        sort(cuboids.begin(), cuboids.end());

        int n = cuboids.size();
        vector<vector<int>> dp(n + 1, vector<int>(n, -1));
        return solve(cuboids, -1, 0, dp);
    }
};
