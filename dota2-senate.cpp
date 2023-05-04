class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<bool> fine;
        int votesD = 0, votesR = 0;
        int d = 0, r = 0;
        
        for(char& c : senate){
            if(c == 'R')
                votesD ? votesD-- : (fine.push(true), votesR++, r++);
            else
                votesR ? votesR-- : (fine.push(false), votesD++, d++);
        }

        while(r && d){
            bool temp = fine.front();
            fine.pop();

            if(temp)
                votesD ? (votesD--, r--) : (fine.push(true), votesR++);
            else
                votesR ? (votesR--, d--) : (fine.push(false), votesD++);
        }

        return fine.front() ? "Radiant" : "Dire";
    }
};