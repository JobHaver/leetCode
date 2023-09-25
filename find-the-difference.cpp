class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> alph(26);

        for(char c : s)
            alph[c - 'a']--;
        
        for(char c : t)
            alph[c - 'a']++;

        return 'a' + (max_element (alph.begin(), alph.end()) - alph.begin());
    }
};