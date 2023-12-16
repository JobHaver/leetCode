class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sLetters(26), tLetters(26);
        for(char c : s)
            sLetters[c - 'a']++;

        for(char c : t)
            tLetters[c - 'a']++;

        for(int i = 0; i < 26; i++)
            if(sLetters[i] != tLetters[i]) return false;

        return true;
    }
};