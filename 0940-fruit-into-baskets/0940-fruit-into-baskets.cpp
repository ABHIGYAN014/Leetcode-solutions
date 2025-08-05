class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int maxi = INT_MIN;
        int left = 0;
        int n = fruits.size();
        for (int right = 0; right < n; right++) {
            mp[fruits[right]]++;
            while (mp.size() > 2) {
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0)
                    mp.erase(fruits[left]);
                left++;
            }

            maxi = max(right - left + 1, maxi);
        }
        return maxi;
    }
};