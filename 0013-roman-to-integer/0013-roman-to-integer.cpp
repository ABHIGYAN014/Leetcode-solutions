class Solution {
public:
    int romanToInt(string s) {
        // Map for Roman numerals and their corresponding integer values
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        
        // Traverse the Roman numeral string
        for (int i = 0; i < s.length(); ++i) {
            // If the current character's value is less than the next character's value
            if (i + 1 < s.length() && roman[s[i]] < roman[s[i + 1]]) {
                total -= roman[s[i]];
            } else {
                total += roman[s[i]];
            }
        }
        
        return total;
    }
};
