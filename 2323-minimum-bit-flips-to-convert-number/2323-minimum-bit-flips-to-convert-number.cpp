class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n=start^goal; 
        int result= __builtin_popcount(n);
        return result;
    }
};