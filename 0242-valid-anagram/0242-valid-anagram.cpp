class Solution {
public:
    bool isAnagram(string s, string t) {
        
      unordered_map<char,int>ans;
      if(s.length()!=t.length())
      {
        return false;
      }

      for(auto ch:s)
      {
        ans[ch]++;
      }

      for(auto ch:t)
      {
        ans[ch]--;
        if(ans[ch]<0)
        {
            return false;
        }
      }
      return true;
    }
};