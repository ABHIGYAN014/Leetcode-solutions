class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>ans;
        for(auto i:nums)
        {
            ans[i]++;
        }

        for(auto i:ans)
        {
            if(i.second>=2) return true;
            
        }
        return false;
    }
};