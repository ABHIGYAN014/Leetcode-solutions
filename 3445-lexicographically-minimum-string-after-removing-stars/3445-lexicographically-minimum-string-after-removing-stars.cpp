class Solution {
public:
    string clearStars(string s) {
        unordered_map<char, stack<int>> um; 
        unordered_set<int> rem;             
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (!um[c].empty()) {
                        rem.insert(um[c].top());
                        um[c].pop();
                        break;
                    }
                }
            } else {
                um[s[i]].push(i); 
            }
        }

        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*' && rem.count(i) == 0) {
                ans += s[i];
            }
        }
        return ans;
    }
};
