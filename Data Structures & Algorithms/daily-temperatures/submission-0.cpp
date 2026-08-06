class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> my_stack;
        vector<int> out(temperatures.size(), 0);
        for(int i = temperatures.size() - 1; i >= 0; i--){
            while(my_stack.size() > 0 && temperatures[my_stack.back()] <= temperatures[i]){
                my_stack.pop_back();
            }
            int val = my_stack.empty() ? 0 : my_stack.back() - i;
            out[i] = val;
            my_stack.push_back(i);
        }
        return out;
    }
};
