class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        struct customLess{
            bool operator()(pair<int,int> a, pair<int,int> b){
                return sqrt(a.first * a.first + a.second * a.second) < sqrt(b.first * b.first + b.second * b.second);
            }
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, customLess> max_heap;
        for(const vector<int> point: points){
            max_heap.push({point[0], point[1]});
            if(max_heap.size() > k){
                max_heap.pop();
            }
        }
        vector<vector<int>> output;
        for(int i = 0; i < k; i++){
            output.push_back({max_heap.top().first, max_heap.top().second});
            max_heap.pop();
        }
        return output;
    }
};
