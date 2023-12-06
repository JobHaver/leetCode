class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        for(int i = 0; n; i++){
            for(int j = 1; n && j < 8; n--, j++)
                ans += i + j;
        }

        return ans;
    }
};