#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) return ans; // Handle the case where the matrix is empty
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int startingRow = 0;
        int endingRow = n - 1;
        int startingCol = 0;
        int endingCol = m - 1;
        
        while (startingRow <= endingRow && startingCol <= endingCol) {
            // Traverse from left to right
            for (int i = startingCol; i <= endingCol; ++i) {
                ans.push_back(matrix[startingRow][i]);
            }
            startingRow++;
            
            // Traverse from top to bottom
            for (int i = startingRow; i <= endingRow; ++i) {
                ans.push_back(matrix[i][endingCol]);
            }
            endingCol--;
            
            if (startingRow <= endingRow) {
                // Traverse from right to left
                for (int i = endingCol; i >= startingCol; --i) {
                    ans.push_back(matrix[endingRow][i]);
                }
                endingRow--;
            }
            
            if (startingCol <= endingCol) {
                // Traverse from bottom to top
                for (int i = endingRow; i >= startingRow; --i) {
                    ans.push_back(matrix[i][startingCol]);
                }
                startingCol++;
            }
        }
        
        return ans;
    }
};
