class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;
        for (int num : nums) {
            xorr ^= num;
        }

        // compute lowest set bit safely in unsigned arithmetic
        unsigned int lastbit = (unsigned int)xorr & (-(unsigned int)xorr);

        int b1 = 0, b2 = 0;
        for (int num : nums) {
            if ((unsigned int)num & lastbit) {
                b1 ^= num;
            } else {
                b2 ^= num;
            }
        }

        return {b1, b2};
    }
};
