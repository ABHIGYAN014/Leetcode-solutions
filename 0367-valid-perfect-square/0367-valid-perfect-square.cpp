class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return true; // 0 and 1 are perfect squares

        int left = 1, right = num;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long squared = mid * mid;

            if (squared == num) {
                return true; // Found a perfect square
            } else if (squared < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false; // Not a perfect square
    }
};
