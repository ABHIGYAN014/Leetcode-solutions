class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        unordered_map<int, int> mp;
        int freq = nums.size() / 3;
        vector<int> ans;
        for (auto i : nums) {
            mp[i]++;
        }

        for (auto i : mp) {
            if (i.second > freq) {
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};