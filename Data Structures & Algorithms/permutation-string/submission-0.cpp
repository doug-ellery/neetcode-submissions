class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length()){return false;}
        array<int, 26> s1_freqs = {};
        array<int, 26> s2_freqs = {};
        for(int i = 0; i < s1.length(); i++){
            s1_freqs[s1[i] - 'a']++;
            s2_freqs[s2[i] - 'a']++;
        }
        int l = 0, r = l + s1.length() - 1;
        while(r < s2.length()){
            if(s1_freqs == s2_freqs){return true;}
            if(r < s2.length() - 1){
                s2_freqs[s2[l] - 'a'] = max(0, s2_freqs[s2[l] - 'a'] - 1);
                s2_freqs[s2[r + 1] - 'a']++;
            }
            l++;
            r++;
        }
        return false;
    }
};
