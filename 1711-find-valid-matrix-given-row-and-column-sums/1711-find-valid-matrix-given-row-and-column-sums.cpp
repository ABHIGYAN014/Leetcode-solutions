class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rkasize = rowSum.size();
        int colkasize = colSum.size();
        vector<vector<int>> result(rkasize, vector<int>(colkasize, 0));

        int i = 0, j = 0;

        while (i < rkasize && j < colkasize) {
            int val = min(rowSum[i], colSum[j]);
            result[i][j] = val;
            rowSum[i] -= val;
            colSum[j] -= val;

            if (rowSum[i] == 0) {
                i++;
            }
            if (colSum[j] == 0) {
                j++;
            }
        }
        return result;
    }
};