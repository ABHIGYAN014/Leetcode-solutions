class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> indexed;
        for (int i = 0; i < nums.size(); i++) {
            indexed.push_back({nums[i], i});
        }
        sort(indexed.begin(), indexed.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });
        vector<pair<int, int>> topk(indexed.begin(), indexed.begin() + k);
        sort(topk.begin(), topk.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<int> ans;
        for (auto &p : topk) ans.push_back(p.first);
        return ans;
    }
};
