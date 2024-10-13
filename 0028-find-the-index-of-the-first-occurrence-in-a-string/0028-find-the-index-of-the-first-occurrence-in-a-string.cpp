class Solution {
public:
    int strStr(string haystack, string needle) {
        // If needle is empty, return 0 as per the problem's requirement
        if (needle.empty()) return 0;

        // Use two pointers to search for the needle in the haystack
        int m = haystack.size();
        int n = needle.size();

        // Loop through the haystack to find the starting index of the needle
        for (int i = 0; i <= m - n; ++i) {
            // Check if the substring starting at i matches the needle
            if (haystack.substr(i, n) == needle) {
                return i;  // Return the starting index if found
            }
        }
        return -1;  // Return -1 if the needle is not found
    }
};