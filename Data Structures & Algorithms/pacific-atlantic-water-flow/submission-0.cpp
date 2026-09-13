class Solution {
public:
    struct dfs_node{
        int row;
        int col;
        dfs_node(int r, int c) : row(r), col(c){}
    };
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));
        stack<dfs_node> dfs_stack;
        for(auto r = 0uz; r < heights.size(); r++){
            pacific[r][0] = true;
            dfs_stack.push(dfs_node(r, 0));
        }
        for(auto c = 1uz; c < heights[0].size(); c++){
            pacific[0][c] = true;
            dfs_stack.push(dfs_node(0, c));
        }
        while(!dfs_stack.empty()){
            int row = dfs_stack.top().row;
            int col = dfs_stack.top().col;
            dfs_stack.pop();
            if(row > 0 && !pacific[row - 1][col] && heights[row - 1][col] >= heights[row][col]){
                dfs_stack.push(dfs_node(row - 1, col));
                pacific[row - 1][col] = true;
            }
            if(row < heights.size() - 1 && !pacific[row + 1][col] && heights[row + 1][col] >= heights[row][col]){
                dfs_stack.push(dfs_node(row + 1, col));
                pacific[row + 1][col] = true;
            }
            if(col > 0 && !pacific[row][col - 1] && heights[row][col - 1] >= heights[row][col]){
                dfs_stack.push(dfs_node(row, col - 1));
                pacific[row][col - 1] = true;
            }
            if(col < heights[0].size() - 1 && !pacific[row][col + 1] && heights[row][col + 1] >= heights[row][col]){
                dfs_stack.push(dfs_node(row, col + 1));
                pacific[row][col + 1] = true;
            }
        }


        for(auto r = 0uz; r < heights.size(); r++){
            atlantic[r][heights[0].size() - 1] = true;
            dfs_stack.push(dfs_node(r, heights[0].size() - 1));
        }
        for(auto c = 0uz; c < heights[0].size() - 1; c++){
            atlantic[heights.size() - 1][c] = true;
            dfs_stack.push(dfs_node(heights.size() - 1, c));
        }
        while(!dfs_stack.empty()){
            int row = dfs_stack.top().row;
            int col = dfs_stack.top().col;
            dfs_stack.pop();
            if(row > 0 && !atlantic[row - 1][col] && heights[row - 1][col] >= heights[row][col]){
                dfs_stack.push(dfs_node(row - 1, col));
                atlantic[row - 1][col] = true;
            }
            if(row < heights.size() - 1 && !atlantic[row + 1][col] && heights[row + 1][col] >= heights[row][col]){
                dfs_stack.push(dfs_node(row + 1, col));
                atlantic[row + 1][col] = true;
            }
            if(col > 0 && !atlantic[row][col - 1] && heights[row][col - 1] >= heights[row][col]){
                dfs_stack.push(dfs_node(row, col - 1));
                atlantic[row][col - 1] = true;
            }
            if(col < heights[0].size() - 1 && !atlantic[row][col + 1] && heights[row][col + 1] >= heights[row][col]){
                dfs_stack.push(dfs_node(row, col + 1));
                atlantic[row][col + 1] = true;
            }
        }
        vector<vector<int>> out;
        for(auto r = 0uz; r < heights.size(); r++){
            for(auto c = 0uz; c < heights[0].size(); c++){
                if(atlantic[r][c] && pacific[r][c]){
                    out.push_back({static_cast<int>(r), static_cast<int>(c)});
                }
            }
        }
        return out;
    }
};
