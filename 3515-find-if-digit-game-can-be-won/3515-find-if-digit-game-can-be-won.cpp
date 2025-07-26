class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int doublee = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] / 10 == 0) {
                sum += nums[i];
            } else {
                doublee+= nums[i];
            }
        }
        bool ans = true;
        if (sum == doublee) {
             ans = false;
        }
        return ans;
    }
};