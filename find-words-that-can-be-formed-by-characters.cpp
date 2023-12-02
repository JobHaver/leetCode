class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> letters(26), comp(26);

        for(char c : chars)
            letters[c - 'a']++;

        int ans = 0, i;
        for(string &s : words){
            comp.assign(letters.begin(), letters.end());  
            for(i = 0; i < s.length() && --comp[s[i] - 'a'] >= 0; i++){}

            if(i == s.length())
                ans += s.length();
        }

        return ans;
    }
};