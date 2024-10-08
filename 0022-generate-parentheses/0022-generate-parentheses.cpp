class Solution {
public:
    // Backtracking function
    void backtrack(std::vector<std::string>& result, std::string current, int open, int close, int max) {
        // If the current combination is of length 2 * max, it's valid
        if (current.length() == 2 * max) {
            result.push_back(current);
            return;
        }

        // If we can add an open parenthesis, add it and recurse
        if (open < max) {
            backtrack(result, current + "(", open + 1, close, max);
        }
        // If we can add a close parenthesis, add it and recurse
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max);
        }
    }

    // Main function
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        // Start backtracking
        backtrack(result, "", 0, 0, n);
        return result;
    }
};