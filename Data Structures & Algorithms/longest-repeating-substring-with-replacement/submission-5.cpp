class Solution {
public:
    int characterReplacement(string s, int k) {
        array<int, 26> freqs = {};
        int l = 0, maxFreq = 0, out = 0;
        char maxFreqChar = '\0';
        //freqs[s[l] - 'A']++;
        for(int r = 0; r < s.length(); r++){
            freqs[s[r] - 'A']++;
            if(freqs[s[r] - 'A'] > maxFreq){
                maxFreq = freqs[s[r] - 'A'];
                maxFreqChar = s[r];
            }
            if(r - l + 1 - maxFreq > k){
                if(s[l] == maxFreqChar){
                    maxFreq--;
                }
                freqs[s[l] - 'A']--;
                l++;
            }
            out = max(r - l + 1, out);
        }
        return out;
    }
};
