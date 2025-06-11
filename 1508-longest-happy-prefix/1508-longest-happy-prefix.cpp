class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector <int> ans(n,0);
        int i=0,j=1;
        while(j<n)
        {
            if(s[i]==s[j])
            {
                ans[j]=i+1;
                i++;j++;
            }
            else
            {
                if(i==0)
                {
                    ans[j]=0;
                    j++;
                }
                else
                {
                    i=ans[i-1];
                }
            }
        }
        return s.substr(0,ans[n-1]);
    }
};