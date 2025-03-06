class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<bool> checked(grid.size() * grid.size() + 1);
        int repeat = -1;
        for(vector<int> &v : grid){
            for(int i : v){
                if(checked[i])
                    repeat = i;
                checked[i] = true;
            }
        }

        for(int i = 1; i < checked.size(); i++)
            if(!checked[i])
                return {repeat, i};

        return {repeat, -1};
    }
};