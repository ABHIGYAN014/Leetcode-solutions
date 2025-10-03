class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        unordered_map<int,int>mp;

        for(auto c:nums)
        {
            mp[c]++;
        }

        for(auto i:mp)
        {
            if(i.second==1)
            {
                return i.first;
                break;
            }
        }
        return 0;
    }
};