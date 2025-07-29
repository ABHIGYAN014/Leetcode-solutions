class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mp;
        for (char c : word) {
            mp[c] = (int)c;
        }

        int count = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            char upper = c - 'a' + 'A'; 

            if (mp.find(c) != mp.end() && mp.find(upper) != mp.end()) {
                count++;
            }
        }
        return count;
    }
};
