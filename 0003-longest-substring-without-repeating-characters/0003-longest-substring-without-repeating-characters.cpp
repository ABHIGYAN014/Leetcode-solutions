#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;  // To store unique characters
        int left = 0;  // Left pointer
        int maxLength = 0;  // Variable to store the maximum length

        // Right pointer moves through the string
        for (int right = 0; right < s.length(); ++right) {
            // If the character is already in the set, move the left pointer
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);  // Remove the character at the left pointer
                left++;  // Move the left pointer to the right
            }
            // Add the current character to the set
            charSet.insert(s[right]);

            // Update the maximum length of the substring
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
