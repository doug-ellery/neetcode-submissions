class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == ""){return 0;}
        int l = 0;
        int r = l + 1;
        int max = 1;
        unordered_map<char, int> map;
        map.insert({s[l],0});
        while(l < s.length() && r < s.length()){
            if(map.find(s[r]) == map.end()){
                max = r - l + 1 > max ? r - l + 1 : max;
                map.insert({s[r], r});
                r++;
            }
            else{
                int prev_l = l;
                l = map[s[r]] + 1;
                map[s[r]] = r;
                
                for(int i = prev_l; i < l - 1; i++){
                    map.erase(s[i]);
                }
                
                r++;
            }
        }
        return max;
    }
};
