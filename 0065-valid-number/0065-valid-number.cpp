class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        bool seenDigit = false, seenExponent = false, seenDot = false;
        
        for (int i = 0; i < n; ++i) {
            char c = s[i];

            // If the character is a digit
            if (isdigit(c)) {
                seenDigit = true;
            } 
            // If the character is a sign (+/-)
            else if (c == '+' || c == '-') {
                // Sign is only allowed at the beginning or right after an 'e' or 'E'
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') return false;
            } 
            // If the character is a dot (.)
            else if (c == '.') {
                // Dot is not allowed if there's an exponent or another dot
                if (seenDot || seenExponent) return false;
                seenDot = true;
            } 
            // If the character is an exponent ('e' or 'E')
            else if (c == 'e' || c == 'E') {
                // Exponent is only allowed if we have seen a digit and not seen another exponent
                if (seenExponent || !seenDigit) return false;
                seenExponent = true;
                seenDigit = false;  // We need digits after the exponent
            } 
            // Invalid character
            else {
                return false;
            }
        }
        
        // In the end, we must have seen at least one digit
        return seenDigit;
    }
};