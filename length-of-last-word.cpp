class Solution {
public:
    int lengthOfLastWord(string s) {
        int i, istart;
        
        for(i = s.length()-1; s[i] == ' '; i--);//get rid of whitespace
        
        istart = i;
        
        for(; i >= 0 && s[i] != ' '; i--);
        
        return istart - i; 
    }
};