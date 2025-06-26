class Solution {
public:

    int squares(int n,vector<int>&dp)
    {
        //base case
        if(n==0) return 1;
        if(n<0) return 0;
        //recursive calls

        if(dp[n]!=-1) return dp[n];

        int ans=INT_MAX;
        int i=1;
        int end=sqrt(n);
        while(i<=end)
        {
            int perfectsquare=i*i;
            int numbrofp=1+squares(n-perfectsquare,dp);
            if(numbrofp<ans)
            {
                ans=numbrofp;
            }
            i++;
        }
          return dp[n]=ans;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return squares(n,dp)-1;
    }
};