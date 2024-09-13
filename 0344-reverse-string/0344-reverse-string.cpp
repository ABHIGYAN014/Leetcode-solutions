class Solution {
public:
// int length(vector<char> &c)
// {
//     int i=0;
//     int length=0;
//     for(int i=0;i<)
// }
    void reverseString(vector<char>& s) {
        int i=0;
        int n= s.size();
        int j=n-1;
        while(i<=j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};