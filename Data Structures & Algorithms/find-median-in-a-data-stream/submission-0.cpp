class MedianFinder {
private:
    priority_queue<int,vector<int>,less<int>> max_heap;
    priority_queue<int,vector<int>, greater<int>> min_heap;
public:
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_heap.empty()){max_heap.push(num);}
        else if(min_heap.empty()){
            int temp = max_heap.top();
            max_heap.pop();
            max_heap.push(min(temp, num));
            min_heap.push(max(temp, num));
        }
        else{
            if(num >= min_heap.top()){
                min_heap.push(num);
                if(min_heap.size() - max_heap.size() > 1){
                    int temp = min_heap.top();
                    min_heap.pop();
                    max_heap.push(temp);
                }
            }
            else{
                max_heap.push(num);
                if(max_heap.size() - min_heap.size() > 1){
                    int temp = max_heap.top();
                    max_heap.pop();
                    min_heap.push(temp);
                }
            }
        }
    }
    
    double findMedian() {
        if(min_heap.size() == max_heap.size()){
            return (double)(min_heap.top() + max_heap.top()) / 2;
        }
        else{
            if(max_heap.size() > min_heap.size()){
                return max_heap.top();
            }
            return min_heap.top();
        }
    }
};
