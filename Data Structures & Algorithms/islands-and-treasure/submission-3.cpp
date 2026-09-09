class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        struct bfs_node{
            int row;
            int col;
            int level;
            bfs_node(int r, int c, int l) : row(r), col(c), level(l){}
        };
        queue<bfs_node> bfs_queue;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(auto r = 0uz; r < grid.size(); r++){
            for(auto c = 0uz; c < grid[0].size(); c++){
                if(grid[r][c] == 0){
                    bfs_queue.push(bfs_node(r, c, 0));
                    visited[r][c] = true;
                }
            }
        }
        while(!bfs_queue.empty()){
            int row = bfs_queue.front().row;
            int col = bfs_queue.front().col;
            int level = bfs_queue.front().level;
            bfs_queue.pop();
            if(row > 0 && !visited[row - 1][col] && grid[row - 1][col] > 0){
                grid[row - 1][col] = level + 1;
                visited[row - 1][col] = true;
                bfs_queue.push(bfs_node(row - 1, col, level + 1));
            }
            if(row < grid.size() - 1 && !visited[row + 1][col] && grid[row + 1][col] > 0){
                grid[row + 1][col] = level + 1;
                visited[row + 1][col] = true;
                bfs_queue.push(bfs_node(row + 1, col, level + 1));
            }
            if(col > 0 && !visited[row][col - 1] && grid[row][col - 1] > 0){
                grid[row][col - 1] = level + 1;
                visited[row][col - 1] = true;
                bfs_queue.push(bfs_node(row, col - 1, level + 1));
            }
            if(col < grid[0].size() - 1 && !visited[row][col + 1] && grid[row][col + 1] > 0){
                grid[row][col + 1] = level + 1;
                visited[row][col + 1] = true;
                bfs_queue.push(bfs_node(row, col + 1, level + 1));
            }
        }
    }
};
