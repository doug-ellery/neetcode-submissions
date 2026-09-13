class Solution {
public:
    struct bfs_node{
        int row;
        int col;
        bfs_node(int r, int c) : row(r), col(c){}
    };
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(auto r = 0uz; r < board.size(); r++){
            for(auto c = 0uz; c < board[0].size(); c++){
                if(!visited[r][c] && board[r][c] == 'O'){
                    queue<bfs_node> bfs_queue;
                    vector<bfs_node> path;
                    bool edge_touched = false;
                    bfs_queue.push(bfs_node(r, c));
                    while(!bfs_queue.empty()){
                        int row = bfs_queue.front().row;
                        int col = bfs_queue.front().col;
                        if(row == 0 || row == board.size() - 1 || col == 0 || col == board[0].size() - 1){
                            edge_touched = true;
                        }
                        path.push_back(bfs_node(row, col));
                        bfs_queue.pop();
                        if(row > 0 && !visited[row - 1][col] && board[row - 1][col] == 'O'){
                            bfs_queue.push(bfs_node(row - 1, col));
                            visited[row - 1][col] = true;
                        }
                        if(row < board.size() - 1 && !visited[row + 1][col] && board[row + 1][col] == 'O'){
                            bfs_queue.push(bfs_node(row + 1, col));
                            visited[row + 1][col] = true;
                        }
                        if(col > 0 && !visited[row][col - 1] && board[row][col - 1] == 'O'){
                            bfs_queue.push(bfs_node(row, col - 1));
                            visited[row][col - 1] = true;
                        }
                        if(col < board[0].size() - 1 && !visited[row][col + 1] && board[row][col + 1] == 'O'){
                            bfs_queue.push(bfs_node(row, col + 1));
                            visited[row][col + 1] = true;
                        }
                    }
                    if(!edge_touched){
                        for(bfs_node node : path){
                            board[node.row][node.col] = 'X';
                        }
                    }
                }
            }
        }
    }
};
