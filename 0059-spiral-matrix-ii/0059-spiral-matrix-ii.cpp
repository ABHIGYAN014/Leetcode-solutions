#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n)); // Initialize n x n matrix with 0s
        int top = 0, bottom = n - 1;  // Top and bottom boundaries
        int left = 0, right = n - 1;  // Left and right boundaries
        int num = 1;  // Current number to fill

        while (top <= bottom && left <= right) {
            // Fill the top row (left to right)
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = num++;
            }
            top++;  // Move the top boundary down

            // Fill the right column (top to bottom)
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = num++;
            }
            right--;  // Move the right boundary left

            if (top <= bottom) {
                // Fill the bottom row (right to left)
                for (int i = right; i >= left; --i) {
                    matrix[bottom][i] = num++;
                }
                bottom--;  // Move the bottom boundary up
            }

            if (left <= right) {
                // Fill the left column (bottom to top)
                for (int i = bottom; i >= top; --i) {
                    matrix[i][left] = num++;
                }
                left++;  // Move the left boundary right
            }
        }

        return matrix;
    }
};
