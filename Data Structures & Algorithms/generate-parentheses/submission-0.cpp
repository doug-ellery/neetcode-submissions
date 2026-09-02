class Solution {
public:
    void helper(int closed_left, int open_left, int closed_used, int open_used, string parens, vector<string>& all_parens, const int n){
        if(closed_used > open_used){return;}
        if(open_used == n && closed_used == n){all_parens.push_back(parens);}
        if(open_left > 0){
            int nxt_open_left = open_left - 1;
            int nxt_open_used = open_used + 1;
            string nxt_parens = parens + "(";
            helper(closed_left, nxt_open_left, closed_used, nxt_open_used, nxt_parens, all_parens, n);
        }
        if(closed_left > 0){
            int nxt_closed_left = closed_left - 1;
            int nxt_closed_used = closed_used + 1;
            string nxt_parens = parens + ")";
            helper(nxt_closed_left, open_left, nxt_closed_used, open_used, nxt_parens, all_parens, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> all_parens;
        helper(n, n, 0, 0, "", all_parens, n);
        return all_parens;
    }
};
