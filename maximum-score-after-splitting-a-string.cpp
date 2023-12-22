class Solution {
public:
    int maxScore(string s) {
        int num1 = 0, num0 = 0;
        for(char c : s)
            if(c == '1') num1++;

        int ans = 0;
        for(int i = 0, size = s.length() - 1; i < size; i++){
            if(s[i] == '0')
                num0++;
            else
                num1--;
            ans = max(ans, num0 + num1);
        }

        return ans;
    }
};