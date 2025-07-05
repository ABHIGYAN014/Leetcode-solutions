class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (auto i : arr) {
            mp[i]++;
        }

        int maxi = -1;
        int ans;
        for (auto i : mp)
        {
            if (i.first == i.second) {
                ans = i.first;
                maxi = max(maxi, ans);
            }
        }
        return maxi;
    }
};