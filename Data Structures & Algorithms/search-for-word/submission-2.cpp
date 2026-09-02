class Solution {
public:
    struct dfs_node{
        int row;
        int col;
        int char_pos;
        dfs_node(int r, int c, int c_p) : row(r), col(c), char_pos(c_p){}
    };
    void run_dfs(dfs_node curr_node, string word, vector<vector<char>>& board, const vector<vector<char>>& og_board, bool& stat){
        int r = curr_node.row;
        int c = curr_node.col;
        int pos = curr_node.char_pos;
        if(pos == word.length() - 1){
            stat = true;
            return;
        }
        board[r][c] = '\0';
        if(r > 0 && board[r - 1][c] == word[pos + 1]){
            run_dfs(dfs_node(r - 1, c, pos + 1), word, board, og_board, stat);
            if(stat){return;}
        }
        if(r < board.size() - 1 && board[r + 1][c] == word[pos + 1]){
            run_dfs(dfs_node(r + 1, c, pos + 1), word, board, og_board, stat);
            if(stat){return;}
        }
        if(c > 0 && board[r][c - 1] == word[pos + 1]){
            run_dfs(dfs_node(r, c - 1, pos + 1), word, board, og_board, stat);
            if(stat){return;}
        }
        if(c < board[0].size() - 1 && board[r][c + 1] == word[pos + 1]){
            run_dfs(dfs_node(r, c + 1, pos + 1), word, board, og_board, stat);
            if(stat){return;}
        }
        board[r][c] = og_board[r][c];
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<char>> board_copy = board;
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                if(board[r][c] == word[0]){
                    bool stat;
                    run_dfs(dfs_node(r, c, 0), word, board_copy, board, stat);
                    if(stat){return true;} 
                }
            }
        }
        return false;
    }
};
