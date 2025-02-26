class Solution {
public:
    void solve(vector<int>&v,int &ans,int &n,int curnum)
    {
        ///base case
        if(curnum==n+1)
        {
            ans++;
            return;
        }
        // /recursive/

        for(int i=1;i<=n;i++)
        {
            if(v[i]==0 &&(curnum%i==0 || i%curnum==0))
            {
                v[i]=curnum;
                solve(v,ans,n,curnum+1);
                v[i]=0;
            }
        }
    }
    int countArrangement(int n) {
        vector<int>v(n+1);
        int ans=0;
        solve(v,ans,n,1);
        return ans;
    }
};