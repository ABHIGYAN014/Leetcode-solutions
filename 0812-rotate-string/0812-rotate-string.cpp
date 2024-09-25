class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        if (s.length() != goal.length()) {
            return false;
        }
        string doubless = s + s;
        return doubless.find(goal) != string::npos;
    }
};
