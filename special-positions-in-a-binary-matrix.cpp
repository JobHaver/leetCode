class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<bool> visited(mat[0].size());
        int ans = 0;

        for(int i = 0; i < mat.size(); i++){
            bool add = false;
            for(int j = 0, cnt = 0; j < mat[i].size(); j++){
                if(!mat[i][j])
                    continue;
                
                if(!visited[j]){
                    visited[j] = true;
                    int y = i + 1;
                    for(; y < mat.size() && !mat[y][j]; y++);
                    add = y == mat.size();
                }

                add = !cnt++ && add;
            }

            if(add)
                ans++;
        }

        return ans;
    }
};