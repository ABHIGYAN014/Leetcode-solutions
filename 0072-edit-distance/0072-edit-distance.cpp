#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.size();
        int n = word2.size();
        
        // DP table to store the minimum edit distance at each state
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        
        // Initialize base cases
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;  // All deletions if word2 is empty
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;  // All insertions if word1 is empty
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::min({dp[i - 1][j - 1] + 1,  // Replace
                                         dp[i][j - 1] + 1,      // Insert
                                         dp[i - 1][j] + 1});    // Delete
                }
            }
        }
        
        return dp[m][n];
    }
};
