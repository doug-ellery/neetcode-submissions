class Solution {
public:
    bool less_or_equal(const array<int, 52>& t_freqs, const array<int, 52>& s_freqs){
        for(int i = 0; i < 52; i++){
            if(!(t_freqs[i] <= s_freqs[i])){return false;}
        }
        return true;
    }
    int hash(char c){
        if(c <= 'Z'){return (int)(c - 'A');}
        return (int)(c - 'A' - 6);
    }
    string minWindow(string s, string t) {
        if(s.length() < t.length()){return "";};
        array<int, 52> s_freqs = {};
        array<int, 52> t_freqs = {};
        for(int i = 0; i < t.length(); i++){
            t_freqs[hash(t[i])]++;
        }
        int l = 0, r = 0;
        while(r < s.length() && !less_or_equal(t_freqs, s_freqs)){
            s_freqs[hash(s[r])]++;
            r++;
        }
        r--;
        if(!less_or_equal(t_freqs, s_freqs)){return "";}
        pair<int,int> my_min = {l, r};
        while(r < s.length()){
            while(less_or_equal(t_freqs, s_freqs)){
                s_freqs[hash(s[l])]--;
                l++;
            }
            if(r - l + 2 < my_min.second - my_min.first + 1){
                my_min = {l - 1, r};
            }
            r++;
            while(r < s.length() && !less_or_equal(t_freqs, s_freqs)){
                s_freqs[hash(s[r])]++;
                r++;
            }
            if(less_or_equal(t_freqs, s_freqs)){
                r--;
            }
        }
        return s.substr(my_min.first, my_min.second - my_min.first + 1);
    }
};
