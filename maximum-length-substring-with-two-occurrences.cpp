class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> alphabet(26);
        int ans = 0;

        for(int i = 0, prevStart = 0, currChar; i < s.size(); i++){
            currChar = s[i]-'a';
            
            for(alphabet[currChar]++; alphabet[currChar] > 2; prevStart++)
                alphabet[s[prevStart]-'a']--;

            ans = max(i - prevStart + 1, ans);
        }

        return ans;
    }
};