class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] >=nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);

        // remaing ke liye
        for (int i = k; i < nums.size(); i++) {
            while (!dq.empty() && i - dq.front() >= k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] >=nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);

            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};