class Solution {
public:
    string largestNumber(vector<int>& nums) {
         // Convert integers to strings for easy comparison
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }

        // Custom sort comparator
        sort(strNums.begin(), strNums.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });

        // If the largest number is "0", return "0"
        if (strNums[0] == "0") {
            return "0";
        }

        // Build the largest number by concatenating sorted strings
        string result;
        for (const string &numStr : strNums) {
            result += numStr;
        }

        return result;
    }
};