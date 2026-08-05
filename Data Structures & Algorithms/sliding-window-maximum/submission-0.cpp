class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> max_heap;
        unordered_map<int,int> freqs;
        for(int i = 0; i < k; i++){
            max_heap.push(nums[i]);
            freqs[nums[i]] = freqs.contains(nums[i]) ? freqs[nums[i]] + 1 : 1;
        }
        vector<int> maxes;
        int l = 0, r = l + k - 1;
        while(r < nums.size()){
            maxes.push_back(max_heap.top());
            if(r < nums.size() - 1){
                freqs[nums[l]]--;
                freqs[nums[r + 1]] = freqs.contains(nums[r + 1]) ? freqs[nums[r + 1]] + 1 : 1;
                max_heap.push(nums[r + 1]);
                while(!max_heap.empty() && freqs[max_heap.top()] < 1){
                    max_heap.pop();
                }
            }
            l++;
            r++;
        }
        return maxes;
    }
};
