class Solution {
public:
    int trap(vector<int>& height) {
        int maxLeft = 0, accum = 0, ans = 0;
        for(int i = 0; i < height.size(); i++){
            if(height[i] >= height[maxLeft]){
                maxLeft = i;
                ans += accum;
                accum = 0;
            }
            else
                accum += height[maxLeft] - height[i];
        }

        accum = 0;
        for(int i = height.size() - 1, maxRight = i; i >= maxLeft; i--){
            if(height[i] >= height[maxRight]){
                maxRight = i;
                ans += accum;
                accum = 0;
            }
            else
                accum += height[maxRight] - height[i];
        }

        return ans;
    }
};