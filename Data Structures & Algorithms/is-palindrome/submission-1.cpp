class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        while(l < r){
            while(!(s[l] <= 'Z' && s[l] >= 'A') &&  !(s[l] <= 'z' && s[l] >= 'a') && !(s[l] <= '9' && s[l] >= '0')){
                l++;
            }
            while(!(s[r] <= 'Z' && s[r] >= 'A') &&  !(s[r] <= 'z' && s[r] >= 'a') && !(s[r] <= '9' && s[r] >= '0')){
                r--;
            }
            if(l < r && tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
