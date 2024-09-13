class Solution {
public:
    string removeOccurrences(string s, string part) {
        int point=s.find(part);
        while(point!= string::npos)
        {
            s.erase(point,part.length());
            point=s.find(part);
        }
        return s;
    }
};