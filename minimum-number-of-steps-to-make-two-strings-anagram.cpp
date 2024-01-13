class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> alph(26);
        for(char c : s)
            alph[c - 'a']++;
        for(char c : t)
            alph[c - 'a']--;
        
        int ans = 0;
        for(int i : alph)
            if(i > 0) ans += i;

        return ans;
    }
};