class Solution {
public:
    bool solve(vector<int>& nums,int target,int index,int sum, vector<vector<int>>&dp)
    {
        if(index>=nums.size()) return false;
        if(sum>target) return false;
        if(sum==target) return true;
        if(dp[index][sum]!=-1) return dp[index][sum];
        int include=solve(nums,target,index+1,sum+nums[index],dp);
        int exclude=solve(nums,target,index+1,sum,dp);

        return dp[index][sum]=include || exclude;
        
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum & 1) return false;

        int target=sum/2;
        int currsum=0;
        int index=0;
        int n=nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        bool ans=solve(nums,target,index,currsum,dp);
        return ans;
    }
};