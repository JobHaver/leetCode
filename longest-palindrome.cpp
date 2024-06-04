class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> alph(60);
        for(char c : s)
            alph[c - 'A']++;
        
        int ans = 0;
        bool odd = false; 
        for(int i : alph){
            if(i & 1){
                ans -= 1;
                odd = true;
            }

            ans += i;
        }

        return ans + odd;
    }
};