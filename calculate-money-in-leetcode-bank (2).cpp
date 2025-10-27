class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int remainder = n % 7;
        int ans = 0;

        //susummations would work better here
        for(int i = 1; i <= weeks; i++)
            ans += 21 + (7 * i);

        for(int i = 1; i <= remainder; i++)
            ans += weeks + i;
        
        return ans;
    }
};