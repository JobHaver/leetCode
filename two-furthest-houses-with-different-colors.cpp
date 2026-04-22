class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        for(int l = 0; l < colors.size() && colors.size() - l > ans; l++){
            for(int r = colors.size()-1; r > l && r - l > ans; r--){
                if(colors[l] != colors[r]){
                    ans = max(ans, r-l);
                    break;
                }
            }
        }

        return ans;
    }
};