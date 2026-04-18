class Solution {
public:
    int mirrorDistance(int n) {
        int reversed = 0;
        for(int temp = n; temp; temp /= 10){
            reversed *= 10;
            reversed += temp % 10;
        }

        return abs(n - reversed);
    }
};