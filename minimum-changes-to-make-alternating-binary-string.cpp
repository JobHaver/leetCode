class Solution {
public:
    int minOperations(string s) {
        int ans1 = 0;
        char curr = '0';
        for(int i = 0; i < s.size(); i++){
            if(s[i] != curr)
                ans1++;

            curr = curr == '0' ? '1' : '0';
        }

        int ans2 = 0;
        curr = '1';
        for(int i = 0; i < s.size(); i++){
            if(s[i] != curr)
                ans2++;

            curr = curr == '0' ? '1' : '0';
        }

        return min(ans1, ans2);
    }
};