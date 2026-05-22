class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9], cols[9], boxes[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                if (rows[i].count(board[i][j])) return false;

                rows[i].insert(board[i][j]);

                if (cols[j].count(board[i][j])) return false;

                cols[j].insert(board[i][j]);

                if (boxes[(i / 3) * 3 + (j / 3)].count(board[i][j])) return false;

                boxes[(i / 3) * 3 + (j / 3)].insert(board[i][j]);
            }
        }

        return true;
    }
};
