class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1 = INT_MAX, min2 = INT_MAX;
        for(int i : prices){
            if(i < min1){
                min1 = i;
                if(min1 < min2)
                    swap(min1, min2);
            }
        }

        int cost = money - min1 - min2;
        return cost < 0 ? money : cost;
    }
};