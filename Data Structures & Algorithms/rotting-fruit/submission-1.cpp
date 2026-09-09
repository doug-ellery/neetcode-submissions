class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        struct bfs_node{
            int row;
            int col;
            int level;
            bfs_node(int r, int c, int l) : row(r), col(c), level(l){}
        };
        queue<bfs_node> bfs_queue;
        bool fresh_fruit = false;
        for(auto r = 0uz; r < grid.size(); r++){
            for(auto c = 0uz; c < grid[0].size(); c++){
                if(grid[r][c] == 2){
                    bfs_queue.push(bfs_node(r, c, 0));
                }
                if(grid[r][c] == 1){
                    fresh_fruit = true;
                }
            }
        }
        if(bfs_queue.empty() && fresh_fruit){return -1;}
        if(bfs_queue.empty() && !fresh_fruit){return 0;}
        int level;
        while(!bfs_queue.empty()){
            int row = bfs_queue.front().row;
            int col = bfs_queue.front().col;
            level = bfs_queue.front().level;
            bfs_queue.pop();
            if(row > 0 && grid[row - 1][col] == 1){
                grid[row - 1][col] = 2;
                bfs_queue.push(bfs_node(row - 1, col, level + 1));
            }
            if(row < grid.size() - 1 && grid[row + 1][col] == 1){
                grid[row + 1][col] = 2;
                bfs_queue.push(bfs_node(row + 1, col, level + 1));
            }
            if(col > 0 && grid[row][col - 1] == 1){
                grid[row][col - 1] = 2;
                bfs_queue.push(bfs_node(row, col - 1, level + 1));
            }
            if(col < grid[0].size() - 1 && grid[row][col + 1] == 1){
                grid[row][col + 1] = 2;
                bfs_queue.push(bfs_node(row, col + 1, level + 1));
            }
        }
        for(auto r = 0uz; r < grid.size(); r++){
            for(auto c = 0uz; c < grid[0].size(); c++){
                if(grid[r][c] == 1){
                    return -1;
                }
            }
        }
        return level;
    }
};
