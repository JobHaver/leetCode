class Solution {
private:
    vector<vector<int>> * grid;
    vector<int> ans;

public:
    vector<int> getBiggestThree(vector<vector<int>>& g) {
        grid = &g;
        ans = {-1, -1, -1};
        for(int i = 0; i < grid->size(); i++)
            for(int j = 0; j < (*grid)[i].size(); j++)
                generatePossibleRhombus(i, j);

        if(ans[1] == -1)
            return {ans[0]};
        else if(ans[2] == -1)
            return {ans[0], ans[1]};

        return ans;
    }

    void generatePossibleRhombus(int y, int x){
        for(int i = 0; i < grid->size(); i++){
            if(y + i >= grid->size() || y - i < 0 || x + (i * 2) >= (*grid)[i].size())
                break;
            
            checkAnswer(getAreaOfRhombus(y, x, i));
        }
    }

    int getAreaOfRhombus(int y, int x, int radius){
        int total = (*grid)[y][x++];
        
        if(radius == 0)
            return total;
            
        for(int i = 1; i < radius; i++, x++)
            total += (*grid)[y + i][x] + (*grid)[y - i][x];
            
        for(int i = radius; i > 0; i--, x++)
            total += (*grid)[y + i][x] + (*grid)[y - i][x];
            
        return total + (*grid)[y][x];
    }

    void checkAnswer(int total){
        if(total == ans[0] || total == ans[1] || total == ans[2])
            return;

        if(total > ans[0])
            ans[2] = ans[1], ans[1] = ans[0], ans[0] = total;
        else if(total > ans[1])
            ans[2] = ans[1], ans[1] = total;
        else if(total > ans[2])
            ans[2] = total;
    }
};