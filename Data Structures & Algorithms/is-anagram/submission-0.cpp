class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        std::vector<char> s_chars, t_chars;
        for(int i = 0; i < s.length(); i++){
            s_chars.push_back(s[i]);
            t_chars.push_back(t[i]);
        }
        std::sort(s_chars.begin(), s_chars.end());
        std::sort(t_chars.begin(), t_chars.end());
        std::string a = "";
        std::string b = "";
        for(int i = 0; i < s.length(); i++){
            a += s_chars[i];
            b += t_chars[i];
        }
        return a == b;
    }
};
