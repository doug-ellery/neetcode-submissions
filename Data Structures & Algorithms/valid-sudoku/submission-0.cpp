class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> cols(9);
        vector<vector<unordered_set<int>>> squares(3, vector<unordered_set<int>>(3));
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                if(board[r][c] == '.'){continue;}
                int r_grid = r / 3;
                int c_grid = c / 3;
                int val = board[r][c] - '0';
                if(rows[r].find(val) != rows[r].end() || cols[c].find(val) != cols[c].end() || squares[r_grid][c_grid].find(val) != squares[r_grid][c_grid].end()){
                    return false;
                }
                rows[r].insert(val);
                cols[c].insert(val);
                squares[r_grid][c_grid].insert(val);
            }
        }
        return true;
    }
};
