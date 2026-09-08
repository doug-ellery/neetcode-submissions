class Solution {
public:
    struct bfs_node{
        int row;
        int col;
        bfs_node(int r, int c) : row(r), col(c){}
    };
    int numIslands(vector<vector<char>>& grid) {
        int num_islands = 0;
        queue<bfs_node> bfs_queue;
        for(auto r = 0uz; r < grid.size(); r++){
            for(auto c = 0uz; c < grid[0].size(); c++){
                if(grid[r][c] == '1'){
                    num_islands++;
                    bfs_queue.push(bfs_node(r, c));
                    grid[r][c] = 0;
                    while(!bfs_queue.empty()){
                        int row = bfs_queue.front().row;
                        int col = bfs_queue.front().col;
                        bfs_queue.pop();
                        if(row > 0 && grid[row - 1][col] == '1'){
                            bfs_queue.push(bfs_node(row - 1, col));
                            grid[row - 1][col] = 0;
                        }
                        if(row < grid.size() - 1 && grid[row + 1][col] == '1'){
                            bfs_queue.push(bfs_node(row + 1, col));
                            grid[row + 1][col] = 0;
                        }
                        if(col > 0 && grid[row][col - 1] == '1'){
                            bfs_queue.push(bfs_node(row, col - 1));
                            grid[row][col - 1] = 0;
                        }
                        if(col < grid[0].size() - 1 && grid[row][col + 1] == '1'){
                            bfs_queue.push(bfs_node(row, col + 1));
                            grid[row][col + 1] = 0;
                        }
                    }
                }
            }
        }
        return num_islands;
    }
};
