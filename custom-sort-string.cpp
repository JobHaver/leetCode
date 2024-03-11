class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> alph(26);
        for(char c : s)
            alph[c-'a']++;
        
        string ans;
        for(char c : order)
            if(alph[c-'a'])
                ans += string(alph[c-'a'], c), alph[c-'a'] = 0;

        for(int i = 0; i < alph.size(); i++)
            if(alph[i])
                ans += string(alph[i], i+'a');

        return ans;
    }
};