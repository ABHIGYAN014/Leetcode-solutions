class Solution {
public:
    string intToRoman(int num) {
        // Define value-symbol pairs
        vector<pair<int, string>> valueSymbols = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, 
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, 
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        
        string roman = "";
        
        // Traverse the value-symbol pairs
        for (const auto& [value, symbol] : valueSymbols) {
            while (num >= value) {
                roman += symbol;  // Append the symbol to the result
                num -= value;      // Reduce the number
            }
        }
        
        return roman;
    }
};
