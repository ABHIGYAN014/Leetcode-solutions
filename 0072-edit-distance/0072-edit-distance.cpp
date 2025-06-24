class Solution {
public:

    int solve(string &s1,string &s2,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=s1.length()) return s2.length()-j;
        if(j>=s2.length()) return s1.length()-i;
        int add=0;
        int replace=0;
        int deletee=0;
        int same=0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j])
        {
            return dp[i][j]=solve(s1,s2,i+1,j+1,dp);
        }
        else
        {
             add=1+solve(s1,s2,i,j+1,dp);
             replace=1+solve(s1,s2,i+1,j+1,dp);
             deletee=1+solve(s1,s2,i+1,j,dp);
        }

        return dp[i][j]=min(add,min(replace,deletee));
        
    }
    int minDistance(string word1, string word2) {
      int i=0;
      int j=0;
      vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
      int ans=solve(word1,word2,i,j,dp);
      return ans;
    }

};