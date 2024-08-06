class Solution {
public:
    int minimumPushes(string word) {
        vector<int> letters(26);

        for(char c : word)
            letters[c - 'a']++;

        int ans = 0;
        sort(letters.begin(), letters.end(), greater<int>());
        for(int i = 0; i < letters.size() && letters[i]; i++)
            ans += letters[i] * (i / 8 + 1);
            
        return ans;
    }
};