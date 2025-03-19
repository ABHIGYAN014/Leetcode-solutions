class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0)
        {
            return true;
        }
        int found=s.find("abc");
        if(found!=string::npos)
        {
            string leftstr=s.substr(0,found);
            string rightstr=s.substr(found+3,s.size());
            return isValid(leftstr+rightstr);
        }
        return false;
    }
};