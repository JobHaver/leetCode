class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int allow = 0, word = 0, ans = 0;

        for(char c : allowed)
            allow |= 1 << (c-'a');

        for(string &s : words){
            for(char c : s)
                word |= 1 << (c-'a');

            if(allow == (word | allow))
                ans++;

            word = 0;
        }

        return ans;
    }
};