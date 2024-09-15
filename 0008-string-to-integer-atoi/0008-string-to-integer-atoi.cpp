class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long result = 0;
        
        // Step 1: Skip leading whitespace
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // Step 2: Check for optional sign character
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert digits to integer
        while (i < s.size() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // Step 4: Handle overflow and clamp to INT range
            if (result * sign >= INT_MAX) return INT_MAX;
            if (result * sign <= INT_MIN) return INT_MIN;
            
            i++;
        }

        return result * sign;
    }
};
