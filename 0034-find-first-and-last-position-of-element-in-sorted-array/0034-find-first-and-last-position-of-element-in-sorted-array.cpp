class Solution {
public:
    // vector<int> solve(vector<int>& nums, int target,vector<int>&ans)
    // {   

    // }
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int>ans;
     
        int index=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        ans.push_back(index);
        int index1=upper_bound(nums.begin(),nums.end(),target)-nums.begin() -1;
        ans.push_back(index1);
        if (index == nums.size() || nums[index] != target) {
            return {-1, -1};
        }
        // return solve(nums,target,ans);
        return ans;
    }
};