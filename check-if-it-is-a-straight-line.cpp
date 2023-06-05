class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int size = coordinates.size();
        float rise = coordinates[0][1] - coordinates[1][1];
        float run = coordinates[0][0] - coordinates[1][0];
        float m = run == 0 ? coordinates[0][0] : rise/run;
        float b = coordinates[0][1] - (coordinates[0][0] * m);

        if(run == 0){
            for(int i = 2; i < size; i++){
                if(coordinates[i][0] != m)
                    return false;
            }
        }
        else{
            for(int i = 2; i < size; i++){
                if(coordinates[i][1] != coordinates[i][0]*m + b)
                    return false;
            }
        }

        return true;
    }
};