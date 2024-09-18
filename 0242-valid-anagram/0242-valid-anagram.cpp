class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int n=s.length();
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
       int final=s.compare(t);
        
        if(final!=0)
        {
            return false;
        }
        return true;
    }
};