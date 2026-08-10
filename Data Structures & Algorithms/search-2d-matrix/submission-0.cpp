class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0, bottom = matrix.size() - 1;
        int row = -1;
        while(top <= bottom){
            int m = (top + bottom) / 2;
            if(target < matrix[m].front()){
                bottom = m - 1;
            }
            else if(target > matrix[m].back()){
                top = m + 1;
            }
            else{
                row = m;
                break;
            }
        }
        if(row == -1){return false;}
        int l = 0, r = matrix[row].size() - 1;
        while(l <= r){
            int m = (l + r) / 2;
            if(target < matrix[row][m]){
                r = m - 1;
            }
            else if(target > matrix[row][m]){
                l = m + 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
