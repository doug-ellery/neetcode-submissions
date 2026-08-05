class Solution {
public:
    function<int(int,int)> get_op(char op){
        if(op == '+'){
            return [](int l, int r){return l + r;};
        }
        if(op == '-'){
            return [](int l, int r){return l - r;};
        }
        if(op == '*'){
            return [](int l, int r){return l*r;};
        }
        return [](int l, int r){return l / r;};
    }
    int evalRPN(vector<string>& tokens) {
        vector<int> nums;
        unordered_set<char> my_set = {'+', '-', '*', '/'};
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i].length() == 1 && my_set.contains(tokens[i][0])){
                function<int(int,int)> op = get_op(tokens[i][0]);
                int start = nums[nums.size() - 2];
                nums[nums.size() - 2] = op(start, nums[nums.size() - 1]);
                nums.pop_back();
            }
            else{
                nums.push_back(stoi(tokens[i]));
            }
        }
        return nums[0];
    }
};
