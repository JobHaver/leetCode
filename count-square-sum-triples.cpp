class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                double root = sqrt(i * i + j * j);
                if(root > n)
                    break;
                if(floor(root) == ceil(root))
                    ans += i == j ? 1 : 2;
            }
        }

        return ans;
    }
};