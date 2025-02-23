class Solution {
public:
    void printValue(vector<vector<string>>& board, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    bool isSafe(int row, int col, vector<vector<string>>& board, int n) {
        int i, j;
        
        // Check leftward (same row)
        for (j = col; j >= 0; j--) {
            if (board[row][j] == "Q") {
                return false;
            }
        }

        // Check upper-left diagonal
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == "Q") {
                return false;
            }
        }

        // Check lower-left diagonal
        for (i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == "Q") {
                return false;
            }
        }

        return true;
    }

    void solve(int n, int col, vector<vector<string>>& board, vector<vector<string>>& result) {
        if (col >= n) {
            vector<string> temp;
            for (int i = 0; i < n; i++) {
                string rowStr = "";
                for (int j = 0; j < n; j++) {
                    rowStr += board[i][j];
                }
                temp.push_back(rowStr);
            }
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isSafe(i, col, board, n)) {
                board[i][col] = "Q";  // Place the queen
                solve(n, col + 1, board, result);
                board[i][col] = ".";  // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n, vector<string>(n, "."));
        vector<vector<string>> result;
        solve(n, 0, board, result);
        return result;
    }
};