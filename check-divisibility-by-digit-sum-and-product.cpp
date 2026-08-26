class Solution {
public:
    bool checkDivisibility(int n) {
        int mult = 1, sum = 0;
        int temp = n;

        for(int currDigit = 0; temp; temp /= 10){
            currDigit = temp % 10;
            mult *= currDigit;
            sum += currDigit;
        }

        return n % (mult + sum) == 0;
    }
};