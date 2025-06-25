class Solution {
public:
    // int solve(vector<int>& nums, int prev, int curr, vector<vector<int>>& dp) {
    //     if (curr >= nums.size())
    //         return 0;

    //     if (dp[curr][prev + 1] != -1)
    //         return dp[curr][prev + 1];

    //     int include = 0;
    //     if (prev == -1 || nums[prev] < nums[curr]) {
    //         include = 1 + solve(nums, curr, curr + 1, dp);
    //     }

    //     int exclude = solve(nums, prev, curr + 1, dp);

    //     return dp[curr][prev + 1] = max(include, exclude);
    // }

    int solveusingBS(vector<int>& nums)
    {
        vector<int>ans;
        ans.push_back(nums[0]);

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>ans.back()) ans.push_back(nums[i]);

            else
            {
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                
            ans[index]=nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // return solve(nums, -1, 0, dp);
        return solveusingBS(nums);
    }
};
