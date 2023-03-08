class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = *max_element(piles.begin(), piles.end());
        int r = isOverflow(max, h) ? max * h : INT_MAX-1; //there is some crazy edge case where max * h is INT_MAX
        int l = 1; // there are no 0's per q outline
        int m;

        while(l < r){
            m = (l + r) / 2;
            if(possible(piles, h, m))
                r = m;
            else
                l = m + 1;
        }

        return l;
    }

    bool possible(vector<int>& piles, int hours, int speed){
        int hoursPassed = 0;
        for(int& p: piles){
            hoursPassed += p / speed;
            if(p % speed)
                hoursPassed++;

            if(hours < hoursPassed)
                return false;
        }

        return true;
    }

    bool isOverflow(long long a, long long b){ //i hate int overflow
        return !(a == (a * b) / b);
    }
};