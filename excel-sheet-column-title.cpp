class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;

        for(; columnNumber--; columnNumber /= 26)
            ans = (char)(columnNumber % 26 + 'A') + ans;

        return ans;
    }
};