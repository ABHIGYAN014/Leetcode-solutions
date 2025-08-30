class Solution {
public:
    int daysreqq(vector<int>& weights, int capacity) {
        int days = 1;
        int load = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] > capacity) {
                days += 1;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int left = *max_element(weights.begin(), weights.end()); 
        int right = accumulate(weights.begin(), weights.end(), 0); 
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int needed = daysreqq(weights, mid);

            if (needed <= days) {
                ans = mid;
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }
        return ans;
    }
};