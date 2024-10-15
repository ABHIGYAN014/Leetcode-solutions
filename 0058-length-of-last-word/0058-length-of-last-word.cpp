class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0; // Length of the last word
        int i = s.length() - 1;

        // Skip any trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count the characters of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};