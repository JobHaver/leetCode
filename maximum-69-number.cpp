class Solution {
public:
    int maximum69Number (int num) {
        int n = num, power = -1;
        for(int i = 0; n; i++){
            if(n % 10 == 6)
                power = i;
            n /= 10;
        }

        if(power == -1)
            return num;

        return num + 3 * pow(10, power);
    }
};