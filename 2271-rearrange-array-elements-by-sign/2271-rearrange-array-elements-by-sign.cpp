class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos_in = 0;
        int neg_in = 1;
        int n = nums.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) 
            {
                ans[neg_in]=nums[i];
                neg_in+=2;
            }

            else
            {
                ans[pos_in]=nums[i];
                pos_in+=2;
            }
        }
        return ans;
    }
};