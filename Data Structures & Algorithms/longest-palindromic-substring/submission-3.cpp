class Solution {
public:
    struct pal_node{
        size_t start;
        size_t end;
    };
    string longestPalindrome(string s) {
        vector<pal_node> center_ones(s.length());
        for(int i = 0; i < s.length(); i++){
            size_t start = i, end = i;
            int l = i - 1, r = i + 1;
            while(l >= 0 && r < s.length() && s[l] == s[r]){
                start = l--;
                end = r++;
            }
            center_ones[i].start = start;
            center_ones[i].end = end;
        }
        vector<pal_node> left_ones(s.length());
        for(int i = 0; i < s.length(); i++){
            size_t start = i, end = i + 1;
            int l = i, r = i + 1;
            while(l >= 0 && r < s.length() && s[l] == s[r]){
                start = l--;
                end = r++;
            }
            left_ones[i].start = start;
            left_ones[i].end = s[start] == s[end] ? end : start;
        }
        pal_node best;
        for(auto i = 0uz; i < s.length(); i++){
            best = center_ones[i].end + 1 - center_ones[i].start > best.end + 1 - best.start ? center_ones[i] : best;
            best = left_ones[i].end + 1 - left_ones[i].start > best.end + 1 - best.start ? left_ones[i] : best;
        }
        return s.substr(best.start, best.end + 1 - best.start);
    }
};
