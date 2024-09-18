class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negCount = lowerBound(nums, 0);
        
        int posCount = nums.size() - lowerBound(nums, 1);
        
        return max(negCount, posCount);
    }
    
    int lowerBound(vector<int>& nums, int x) {
        int left = 0, right = nums.size();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
};
