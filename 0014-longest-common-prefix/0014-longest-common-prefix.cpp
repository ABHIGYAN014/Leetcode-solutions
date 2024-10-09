class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         if (strs.empty()) return ""; // Step 1: Check for empty input

        string prefix = strs[0]; // Step 2: Initialize prefix with the first string

        // Step 3: Compare prefix with each string in the array
        for (int i = 1; i < strs.size(); i++) {
            // Reduce the prefix while it doesn't match the beginning of strs[i]
            while (strs[i].find(prefix) != 0) { 
                prefix = prefix.substr(0, prefix.size() - 1); // Shorten the prefix
                if (prefix.empty()) return ""; // If prefix is empty, return ""
            }
        }

        return prefix; 
    }
};