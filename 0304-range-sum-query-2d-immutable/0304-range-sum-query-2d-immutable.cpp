class NumMatrix {
public:
    vector<vector<int>> ans;

    NumMatrix(vector<vector<int>>& matrix) {
        ans = matrix;
        int row = matrix.size();
        int col = matrix[0].size();

        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ans[i][j] += ans[i - 1][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        if (row1 == 0) {
            for (int i = col1; i <= col2; i++) {
                sum += ans[row2][i];
            }
        } else {
            for (int i = col1; i <= col2; i++) {
                sum += ans[row2][i] - ans[row1 - 1][i];
            }
        }
        return sum;
    }
};
