class Solution {
public:
    bool isValid(string s) {
        vector<char> my_stack;
        unordered_map<char, char> openers = {{'(', ')'},{'{', '}'},{'[', ']'}};
        for(int i = 0; i < s.length(); i++){
            if(openers.contains(s[i])){
                my_stack.push_back(s[i]);
            }
            else{
                if(my_stack.size() > 0 && openers[my_stack.back()] == s[i]){
                    my_stack.pop_back();
                }
                else{
                    return false;
                }
            }
        }
        return my_stack.size() == 0;
    }
};
