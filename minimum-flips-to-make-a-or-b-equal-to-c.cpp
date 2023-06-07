class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;

        for(; a || b || c; a>>=1, b>>=1, c>>=1){
            if(c&1){
                if(!(a&1 || b&1))
                    flips++;
            }
            else{
                if(a&1)
                    flips++;
                if(b&1)
                    flips++;
            }
        }

        return flips;
    }
};