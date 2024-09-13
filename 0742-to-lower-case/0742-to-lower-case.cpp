class Solution {
public:
    string toLowerCase(string s) {
        int i=0;
        // string k;
        int n= s.size();
        int j=n-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
        s[i]=s[i]-'A'+'a';
            }
        }
        return s;
    }
};