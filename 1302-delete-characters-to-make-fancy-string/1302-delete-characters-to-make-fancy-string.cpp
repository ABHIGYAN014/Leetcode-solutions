class Solution {
public:
    string makeFancyString(string s) {
        int count = 0;
        char prevchar = s[0];
        vector<char> ans;

        for (char c : s) {
            if (c == prevchar) {
                count++;
            } else {
                count = 1;
                prevchar = c;
            }

            if (count <= 2) {
                ans.push_back(c);
            }
        }

        return string(ans.begin(), ans.end());
    }
};
