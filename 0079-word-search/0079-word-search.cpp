class Solution {
public:
    bool search(string& str, int x, int i, int j, vector<vector<char>>& board) {
        if (str[x] != board[i][j]) {
            return false;
        } else {
            char prev = board[i][j];
            if (x == str.size() - 1) {
                return true;
            }
            board[i][j] = '#';
            bool ans = false;
            if (i + 1 < board.size()) {
                ans |= search(str, x + 1, i + 1, j, board);
            }
            if (i - 1 >= 0) {
                ans |= search(str, x + 1, i - 1, j, board);
            }
            if (j + 1 < board[0].size()) {
                ans |= search(str, x + 1, i, j + 1, board);
            }
            if (j - 1 >= 0) {
                ans |= search(str, x + 1, i, j - 1, board);
            }
            board[i][j] = prev;
            return ans;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                ans |= search(word, 0, i, j, board);
            }
        }
        return ans;
    }
};