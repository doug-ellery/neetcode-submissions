class Solution {
public:
    int characterReplacement(string s, int k) {
        int max = 1 + k;
        int l = 0;
        int r = 1;
        int used = 0;
        int len = 1;
        while(l < s.length() - 1 && r < s.length()){
            if(s[l] != s[r]){
                if(used < k){
                    if(r == s.length() - 1){
                        int len = r - l + (k - used);
                        len = len > s.length() ? s.length() : len;
                        max = len > max ? len : max;
                        l++;
                        while(s[l] == s[l - 1]){
                            l++;
                        }
                        r = l + 1;
                        used = 0;
                    }
                    else{
                        used++;
                        r++;
                    }
                }
                else{
                    int len = r - l;
                    max = len > max ? len : max;
                    l++;
                    while(s[l] == s[l - 1]){
                        l++;
                    }
                    r = l + 1;
                    used = 0;
                }
            }
            else{
                if(r == s.length() - 1){
                    int len = r - l + 1 + (k - used);
                    len = len > s.length() ? s.length() : len;
                    max = len > max ? len : max;
                }
                r++;
            }
        }
        return max;
    }
};
