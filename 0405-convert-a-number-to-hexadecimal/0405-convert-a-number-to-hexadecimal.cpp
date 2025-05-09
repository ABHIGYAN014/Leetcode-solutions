class Solution {
public:
    string toHex(int num) {
        if(num==0) return "0";
        unsigned int mynumber=num;
        string res;
        string hex="0123456789abcdef";
        while(mynumber)
        {
            res=res+hex[mynumber%16];
            mynumber/=16;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};