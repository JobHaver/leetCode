class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sLetters(26), tLetters(26);
        for(char c : s)
            sLetters[c - 'a']++;

        for(char c : t)
            tLetters[c - 'a']++;

        return sLetters == tLetters;
    }
};