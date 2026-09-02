class Solution {
public:
    struct dfs_node{
        int row;
        int col;
        int char_pos;
        vector<vector<char>> board;
        dfs_node(int r, int c, int c_p, vector<vector<char>> b) : row(r), col(c), char_pos(c_p), board(b){}
    };
    bool run_dfs(dfs_node start, string word){
        stack<dfs_node> dfs_stack;
        dfs_stack.push(start);
        while(!dfs_stack.empty()){
            dfs_node curr_node = dfs_stack.top();
            dfs_stack.pop();
            int pos = curr_node.char_pos;
            int r = curr_node.row;
            int c = curr_node.col;
            vector<vector<char>> board = curr_node.board;
            board[r][c] = '\0';
            if(pos == word.length() - 1){
                return true;
            }
            if(r > 0 && board[r - 1][c] == word[pos + 1]){
                dfs_stack.push(dfs_node(r - 1, c, pos + 1, board));
            }
            if(r < board.size() - 1 && board[r + 1][c] == word[pos + 1]){
                dfs_stack.push(dfs_node(r + 1, c, pos + 1, board));
            }
            if(c > 0 && board[r][c - 1] == word[pos + 1]){
                dfs_stack.push(dfs_node(r, c - 1, pos + 1, board));
            }
            if(c < board[0].size() - 1 && board[r][c + 1] == word[pos + 1]){
                dfs_stack.push(dfs_node(r, c + 1, pos + 1, board));
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                if(board[r][c] == word[0]){
                    if(run_dfs(dfs_node(r, c, 0, board), word)){
                        return true;
                    } 
                }
            }
        }
        return false;
    }
};
