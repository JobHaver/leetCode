class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans(img.size(), vector<int>(img[0].size()));
        for(int i = 0; i < img.size(); i++){
            for(int j = 0; j < img[i].size(); j++){
                int tot = 0, sum = 0;
                for(int x = -1; x < 2; x++){
                    for(int y = -1; y < 2; y++){
                        int xi = i + x, yj = y + j;
                        if(xi >= 0 && yj >= 0 && xi < img.size() && yj < img[i].size())
                            sum += img[xi][yj], tot++;
                    }
                }

                ans[i][j] = sum / tot;
            }
        }

        return ans;
    }
};