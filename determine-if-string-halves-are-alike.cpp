class Solution {
public:
    bool halvesAreAlike(string s) {
        vector<int> alph(26);
        vector<char> check{'a', 'e', 'i', 'o', 'u'};
        int half = s.size()/2;
        for(int i = 0; i < half; i++)
            alph[(char)tolower(s[i]) - 'a']++;
        for(int i = half; i < s.size(); i++)
            alph[(char)tolower(s[i]) - 'a']--;

        int tot = 0;
        for(char c : check)
            tot += alph[c - 'a'];

        return !tot;
    }
};