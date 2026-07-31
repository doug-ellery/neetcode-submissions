class Solution {
public:
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
        std::unordered_map<string, int> seen_words;
        std::vector<std::vector<std::string>> output;
        for(int i = 0; i < strs.size(); i++){
            std::string base = base_string(strs[i]);
            if(seen_words.count(base)){
                output[seen_words[base]].push_back(strs[i]);
            }
            else{
                output.push_back({strs[i]});
                seen_words.insert({base,output.size() - 1});
            }
        }
        return output;
    }
};
