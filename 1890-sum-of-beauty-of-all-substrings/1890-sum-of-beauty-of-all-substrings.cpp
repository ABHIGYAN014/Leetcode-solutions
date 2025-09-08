class Solution {
public:
    int maxi(vector<int>& freq) {
        int maxi = INT_MIN;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxi) {
                maxi = freq[i];
            }
        }
        return maxi;
    }

    int mini(vector<int>& freq) {
        int mini = INT_MAX;

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                if (freq[i] < mini) {
                    mini = freq[i];
                }
            }
        }
        return mini;
    }
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int beauty = maxi(freq) - mini(freq);
                sum += beauty;
            }
        }
        return sum;
    }
};