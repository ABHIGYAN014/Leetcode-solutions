class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mpp;
        for (char ch : p) {
            mpp[ch]++;
        }

        int cnt = mpp.size(); 
        int k = p.length();  
        int i = 0, j = 0;
        vector<int> ans;

        while (j < s.length()) {
            if (mpp.count(s[j])) {
                mpp[s[j]]--;
                if (mpp[s[j]] == 0) {
                    cnt--;
                }
            }
            if (j - i + 1 < k) {
                j++;
            }
            else if (j - i + 1 == k) {
                if (cnt == 0) {
                    ans.push_back(i); 
                }
                if (mpp.count(s[i])) {
                    if (mpp[s[i]] == 0) {
                        cnt++;
                    }
                    mpp[s[i]]++;
                }

                i++;
                j++;
            }
        }

        return ans;
    }
};