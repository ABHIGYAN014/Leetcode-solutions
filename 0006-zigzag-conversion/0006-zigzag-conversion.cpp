class Solution {
public:
    string convert(string s, int numRows) {
        // Handle edge cases
        if (numRows <= 1 || numRows >= s.size()) {
            return s;
        }

        string result;
        int cycleLen = 2 * numRows - 2; // Length of a cycle in the zigzag pattern

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j + i < s.size(); j += cycleLen) {
                result += s[j + i]; // Get the vertical part

                // Get the diagonal part (only for rows 1 to numRows-2)
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < s.size()) {
                    result += s[j + cycleLen - i];
                }
            }
        }

        return result;
    }
};
