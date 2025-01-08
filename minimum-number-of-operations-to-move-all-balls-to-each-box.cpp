class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size());
        int numBallsR = 0, numBallsL = 0, totalR = 0, totalL = 0;;
        
        for(int i = boxes.size()-1; i > -1; i--){
            totalR += numBallsR;
            if(boxes[i] == '1')
                numBallsR++;
        }

        for(int i = 0; i < boxes.size(); i++){
            ans[i] = totalR + totalL;
            if(boxes[i] == '1')
                numBallsR--, numBallsL++;
            
            totalR -= numBallsR;
            totalL += numBallsL;
        }

        return ans;
    }
};