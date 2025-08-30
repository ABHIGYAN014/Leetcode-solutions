class Solution {
public:

    int divisor(vector<int>& nums, int value) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += (nums[i] + value - 1) / value;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1; 
        int r = *max_element(nums.begin(), nums.end());
        int ans = r;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int value = divisor(nums, mid);
            
            if(value <= threshold) {
                ans = mid;   
                r = mid - 1;
            } else {
                l = mid + 1; 
            }
        }
        return ans;
    }
};
