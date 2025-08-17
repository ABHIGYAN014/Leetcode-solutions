class Solution {
public:
    string toHex(int num) {
        string hex;

        if(num==0)
        {
            return "0";
        }
        unsigned int temp=num;
        int rem=0;
        while(temp>0)
        {
            rem=temp%16;

            if(rem<10)
            {
                hex+=48+rem;
            }
            else
            {
                hex+=87+rem;
            }

            temp=temp/16;
        }

        reverse(hex.begin(),hex.end());
        return hex;
    }
};