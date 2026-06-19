class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int curr = 0;
        
        for(int i : gain)
            ans = max(curr += i, ans);

        return ans;
    }
};