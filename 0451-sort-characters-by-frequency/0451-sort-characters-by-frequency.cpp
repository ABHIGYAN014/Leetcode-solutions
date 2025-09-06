class Solution {
public:
    static bool cmp(pair<char, int>& a, pair<char, int>& b) {
        return a.second >
               b.second; // comparater define kiye hai for sorting thing
    }
    string frequencySort(string s) {

        unordered_map<char, int> mp; // map bnaye
        string result = "";
        for (auto c : s) {
            mp[c]++; // freq map krr rhe hai
        }

        vector<pair<char, int>> charac; // array bnaye

        for (auto i : mp) {
            charac.push_back({i.first, i.second}); // array mai daal rhe hai
        }

        sort(charac.begin(), charac.end(), cmp); // desc on basis of value(freq)

        for (auto ch : charac) {
            int count = ch.second;
            char chrr = ch.first;
            result.append(count, chrr); // build krenge result ko
        }
        return result;
    }
};