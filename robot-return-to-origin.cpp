class Solution {
public:
    bool judgeCircle(string moves) {
        int y = 0, x = 0;
        for(char c : moves){
            switch(c){
                case 'U': y++; break;
                case 'D': y--; break;
                case 'L': x--; break;
                case 'R': x++; break;
            }
        }

        return !y && !x;
    }
};