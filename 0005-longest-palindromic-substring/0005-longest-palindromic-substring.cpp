class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.size() == 1) return s;
        
        int start = 0, maxLength = 1;
        
        for (int i = 0; i < s.size(); i++) {
            // Odd length palindrome (single center character)
            int len1 = expandAroundCenter(s, i, i);
            // Even length palindrome (center between two characters)
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int len = max(len1, len2);
            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLength);
    }
    
private:
    int expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;  // Length of the palindrome
    }
};
