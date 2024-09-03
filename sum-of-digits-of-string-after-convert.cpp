class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0, n;
        for(char c : s)
            for(n = c - 'a' + 1; n > 0; n /= 10)
                ans += n % 10;

        while(--k)
            for(n = ans, ans = 0; n > 0; n /= 10)
                ans += n % 10;
        
        return ans;
    }
};