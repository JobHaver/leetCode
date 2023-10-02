class Solution {
public:
    bool winnerOfGame(string colors) {
        int cntA = 0, cntB = 0, size = colors.size() - 1;

        for(int i = 1; i < size; i++){
            if(colors[i] == colors[i - 1] && colors[i] == colors[i + 1])
                colors[i] == 'A' ? cntA++ : cntB++;
        }

        return cntA > cntB;
    }
};