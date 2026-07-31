class Solution {
public:

    string encode(vector<string>& strs) {
        string out = "";
        for(string str : strs){
            out += to_string(str.length()) + "#";
            out += str;
        }
        return out;
    }

    vector<string> decode(string s) {
        vector<string> outs;
        for(int i = 0; i < s.length(); ){
            int found = s.find('#', i);
            int size = stoi(s.substr(i, found - i));
            i = found + 1;
            string out = s.substr(i, size);
            i += size;
            outs.push_back(out);
        }
        return outs;
    }
};