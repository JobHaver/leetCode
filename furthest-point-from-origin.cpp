class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count = 0, wildcard = 0;
        for(char c : moves){
            if(c == 'L')
                count++;
            else if(c == 'R')
                count--;
            else
                wildcard++;
        }

        return abs(count) + wildcard;
    }
};