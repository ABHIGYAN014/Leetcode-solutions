class Solution {
public:
    bool palind(string s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                return false;
                
            }
            i++;
                j--;
           
        }
         return true;
    }
    bool validPalindrome(string s) 
    {
         int i=0;
         int j=s.length()-1;
         while(i<=j)
         {
            if(s[i]!=s[j])
            {
                return palind(s,i+1,j) || palind(s,i,j-1);
            }
            else
            {
                i++;
                j--;
            }
         }
         return true;
    }
};