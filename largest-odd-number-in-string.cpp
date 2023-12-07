class Solution {
public:
    string largestOddNumber(string num) {
        int i;
        for(i = num.length() - 1; i >= 0 && !((num[i] - '0') % 2); i--){}

        return num.substr(0, i + 1);
    }
};