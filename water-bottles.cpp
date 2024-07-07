class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = 0, ans = 0;
        for(; numBottles + empty >= numExchange; ){
            ans += numBottles;
            empty += numBottles;
            numBottles = empty / numExchange;
            empty %= numExchange;
        }

        return ans + numBottles;
    }
};