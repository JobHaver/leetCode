class Solution {
public:
    bool pally(string &s){
        for(int l = 0, r = s.size() - 1; l < r; l++, r--)
            if(s[l] != s[r])
                return false;

        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for(string &s : words)
            if(pally(s))
                return s;

        return "";
    }
};