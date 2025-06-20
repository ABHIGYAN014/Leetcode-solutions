class Solution {
public:
    int solve(int n,vector<int>&nums,vector<int>&dp,int i)
    {
        if(i>=n)
        {
            return 0;
        }

        if(dp[i]!=INT_MIN)
        {
            return dp[i];
        }

        int opt1=nums[i]+solve(n,nums,dp,i+2);
        int opt2=0+solve(n,nums,dp,i+1);

        dp[i]=max(opt1,opt2);

        return dp[i];
    }
        int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,INT_MIN);
        int i=0;
        return solve(n,nums,dp,i);
    }
};