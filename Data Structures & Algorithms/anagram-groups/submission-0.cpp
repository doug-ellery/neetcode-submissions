class Solution {
public:
    bool is_anagram(std::string s, std::string t){
        return base_string(s) == base_string(t);
    }
    std::string base_string(std::string wrd){
        vector<char> chars;
        for(int i = 0; i < wrd.length(); i++){
            chars.push_back(wrd[i]);
        }
        std::sort(chars.begin(), chars.end());
        std::string out = "";
        for(int i = 0; i < chars.size(); i++){
            out += chars[i];
        }
        return out;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_set<string> seen_words;
        std::vector<std::vector<std::string>> output;
        for(int i = 0; i < strs.size(); i++){
            if(seen_words.count(base_string(strs[i]))){
                for(auto& group : output){
                    if(is_anagram(group[0], strs[i])){
                        group.push_back(strs[i]);
                    }
                }
            }
            else{
                output.push_back({strs[i]});
                seen_words.insert(base_string(strs[i]));
            }
        }
        return output;
    }
};
