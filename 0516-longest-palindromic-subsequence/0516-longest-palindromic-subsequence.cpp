class Solution {
public:
    int solve(string&s,string&a,int i,int j, vector<vector<int>>&dp)
    {
        if(i>=s.length()) return 0;
        if(j>=a.length()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int same=0;
        int dif=0;
        if(s[i]==a[j])
        {
            same =1+solve(s,a,i+1,j+1,dp);
        }
        else
        {
            dif=0+max(solve(s,a,i,j+1,dp),solve(s,a,i+1,j,dp));
        }

        int final=max(same,dif);

        dp[i][j]=final;
         return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        
        /// Approch jo hai ki iska hi reverse nikal deta hu fir uss reverse aur original ka LCS nikal lunga
        string a=s;
        reverse(a.begin(),a.end());
        int i=0;
        int j=0;
        vector<vector<int>>dp(s.length(),vector<int>(a.length(),-1));
        int ans=solve(s,a,i,j,dp);
     
        return ans;
    }
};