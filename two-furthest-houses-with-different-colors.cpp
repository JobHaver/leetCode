class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        for(int l = 0, r = colors.size()-1; l < r; r--){
            if(colors[l] != colors[r]){
                ans = max(ans, r-l);
                    break;
            }
        }

        for(int l = 0, r = colors.size()-1; l < r; l++){
            if(colors[l] != colors[r]){
                ans = max(ans, r-l);
                    break;
            }
        }

        return ans;
    }
};