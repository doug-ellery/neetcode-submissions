class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap;
        for(const auto& stone : stones){
            max_heap.push(stone);
        }
        while(max_heap.size() > 1){
            int x = max_heap.top();
            max_heap.pop();
            int y = max_heap.top();
            max_heap.pop();
            if(x != y){
                max_heap.push(max(x,y) - min(x,y));
            }
        }
        return max_heap.empty() ? 0 : max_heap.top();
    }
};
