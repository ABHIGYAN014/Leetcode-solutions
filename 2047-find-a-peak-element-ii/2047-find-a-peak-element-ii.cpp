class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        int start = 0, end = col - 1;
        vector<int> ans;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int maxRow = 0;

            for (int i = 0; i < row; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            bool leftIsBigger = (mid > 0 && mat[maxRow][mid - 1] > mat[maxRow][mid]);
            bool rightIsBigger = (mid < col - 1 && mat[maxRow][mid + 1] > mat[maxRow][mid]);

            if (!leftIsBigger && !rightIsBigger) {
                ans = {maxRow, mid};
                break;
            } 
            else if (rightIsBigger) {
                start = mid + 1;
            } 
            else {
                end = mid - 1;   
            }
        }
        return ans;
    }
};
