public class Solution {
    public int MinimumLength(string s) {
        int l = 0, r = s.Length-1;
        while(l < r && s[l] == s[r]){
            for(char c = s[l]; l <= r && s[l] == c; l++);
            for(char c = s[r]; l <= r && s[r] == c; r--);
        }

        return r - l + 1;
    }
}