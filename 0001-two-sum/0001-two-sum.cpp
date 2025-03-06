#include <unordered_map>
 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]+nums[i+1]==target)
            {
                ans.push_back(i);
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
