class Solution {
public:
    void backtrack(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(current);

        // Explore further by including each element one by one
        for (int i = index; i < nums.size(); i++) {
            // Include the current element
            current.push_back(nums[i]);

            // Recur to generate further subsets
            backtrack(nums, i + 1, current, result);

            // Backtrack and remove the element to explore other possibilities
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
};
