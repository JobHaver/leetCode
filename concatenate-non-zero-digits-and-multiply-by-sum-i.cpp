class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0, sum = 0;
        for(int depth = 0; n; n /= 10){
            int i = n % 10;
            if(!i)
                continue;
                
            ans += i * pow(10, depth++);
            sum += i;
        }

        return ans * sum;
    }
};