class Solution {
public:
    int countHomogenous(string s) {
        int ans = 0;
        pair<char, int> last = {'!', 0};
        
        #pragma unroll
        for(char &c : s){
            if(last.first != c)
                last = {c, 0};

            ans += ++last.second;
            ans %= 1000000007;
        }

        return ans;
    }
};