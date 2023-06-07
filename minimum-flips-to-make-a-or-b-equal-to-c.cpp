class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;

        for(; a || b || c; a>>=1, b>>=1, c>>=1){
            bool aB = a&1, bB = b&1, cB = c&1;

            if(cB){
                if(!(aB || bB))
                    flips++;
            }
            else{
                if(aB)
                    flips++;
                if(bB)
                    flips++;
            }
        }

        return flips;
    }
};