class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n=start^goal; 
        int result= 0;
        while(n>0)
        {
            n=n &(n-1);
            result++;
        }
        return result;
    }
};