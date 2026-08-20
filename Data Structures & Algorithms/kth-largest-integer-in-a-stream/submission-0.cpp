class KthLargest {
private:
    priority_queue<int> max_heap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(const auto& num : nums){
            max_heap.push(num);
        }
    }
    
    int add(int val) {
        vector<int> temp_holdings;
        max_heap.push(val);
        for(int i = 0; i < k; i++){
            temp_holdings.push_back(max_heap.top());
            max_heap.pop();
        }
        int kth_largest = temp_holdings.back();
        for(const auto& num : temp_holdings){
            max_heap.push(num);
        }
        return kth_largest;
    }
};
