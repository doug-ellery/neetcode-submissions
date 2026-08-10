class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int,int>> right_stack;
        vector<pair<int,int>> left_stack;
        vector<int> right_bounds(heights.size(), 0);
        vector<int> left_bounds(heights.size(), 0);
        for(int i = 0; i < heights.size(); i++){
            int j = heights.size() - 1 - i;
            if(right_stack.empty() || heights[i] >= right_stack.back().first){
                right_stack.push_back({heights[i], i});
            }
            else{
                while(!right_stack.empty() && heights[i] < right_stack.back().first){
                    right_bounds[right_stack.back().second] = i - 1;
                    right_stack.pop_back();
                }
                right_stack.push_back({heights[i], i});
            }

            if(left_stack.empty() || heights[j] >= left_stack.back().first){
                left_stack.push_back({heights[j], j});
            }
            else{
                while(!left_stack.empty() && heights[j] < left_stack.back().first){
                    left_bounds[left_stack.back().second] = j + 1;
                    left_stack.pop_back();
                }
                left_stack.push_back({heights[j], j});
            }
        }
        while(!right_stack.empty()){
            right_bounds[right_stack.back().second] = heights.size() - 1;
            right_stack.pop_back();
        }
        while(!left_stack.empty()){
            left_bounds[left_stack.back().second] = 0;
            left_stack.pop_back();
        }
        int my_max = INT_MIN;
        for(int i = 0; i < heights.size(); i++){
            int area = (right_bounds[i] - left_bounds[i] + 1) * heights[i];
            my_max = max(my_max, area);
        }
        return my_max;
    }
};
