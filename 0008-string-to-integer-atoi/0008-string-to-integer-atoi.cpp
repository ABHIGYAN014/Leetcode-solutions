class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        while (i < s.length() && s[i] == ' ') {
            i++;
        }
        int sign = 1;
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '+') {
                sign = 1;
            } else {
                sign = -1;
            }
            i++;
        }
        long result = 0;
        while (i < s.length() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            if (result * sign > INT_MAX)
                return INT_MAX;
            if (result * sign < INT_MIN)
                return INT_MIN;

            i++;
        }

        return result * sign;
    }
};