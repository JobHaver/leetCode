class Solution {
public:
    int maxProduct(int n) {
        int firstMax = 0, secondMax = 0;

        while(n){
            int curr = n % 10;

            if(curr > firstMax){
                secondMax = firstMax;
                firstMax = curr;
            }
            else if(curr > secondMax)
                secondMax = curr;

            n /= 10;
        }

        return firstMax * secondMax;
    }
};