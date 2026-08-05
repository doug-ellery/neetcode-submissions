class Solution {
public:
    int apply_op(char op, int l, int r){
        switch(op){
            case '+': return l + r;
            case '*': return l * r;
            case '-': return l - r;
            default: return l / r;
        }
    }
    int evalRPN(vector<string>& tokens) {
        vector<int> nums;
        unordered_set<char> my_set = {'+', '-', '*', '/'};
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i].length() == 1 && my_set.contains(tokens[i][0])){
                nums[nums.size() - 2] = apply_op(tokens[i][0], nums[nums.size() - 2], nums[nums.size() - 1]);
                nums.pop_back();
            }
            else{
                nums.push_back(stoi(tokens[i]));
            }
        }
        return nums[0];
    }
};
