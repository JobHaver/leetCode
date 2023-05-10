class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int disX = n, disY = n;
        int x = -1, y = 0, j = 1;

        while(true){
            for(int i = 0; i < disX; i++)
                ans[y][++x] = j++;
            if(!--disY)
                break;

            for(int i = 0; i < disY; i++)
                ans[++y][x] = j++;
            if(!--disX)
                break;

            for(int i = 0; i < disX; i++)
                ans[y][--x] = j++;
            if(!--disY)
                break;

            for(int i = 0; i < disY; i++)
                ans[--y][x] = j++;
            if(!--disX)
                break;
        }

        return ans;
    }
};