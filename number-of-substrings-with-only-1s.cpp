class Solution {
public:
    int numSub(string s) {
        long long ans = 0;
        int countOfOnes = 0;

        for(char c : s){
            if(c == '1')
                ans += ++countOfOnes;
            else
                countOfOnes = 0;
        }

        return ans % 1000000007;
    }
};