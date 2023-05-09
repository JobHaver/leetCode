class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int disX = matrix[0].size(), disY = matrix.size(), size = disX * disY;
        vector<int> ans(size);
        int x = -1, y = 0, j = 0;

        while(true){
            for(int i = 0; i < disX; i++)
                ans[j++] = matrix[y][++x];
            if(!--disY)
                break;

            for(int i = 0; i < disY; i++)
                ans[j++] = matrix[++y][x];
            if(!--disX)
                break;

            for(int i = 0; i < disX; i++)
                ans[j++] = matrix[y][--x];
            if(!--disY)
                break;

            for(int i = 0; i < disY; i++)
                ans[j++] = matrix[--y][x];
            if(!--disX)
                break;
        }

        return ans;
    }
};