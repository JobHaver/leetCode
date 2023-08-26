class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int ans = 0, end = -1001; //-1001 bc -1000 is min val

        sort(pairs.begin(), pairs.end());
        for(vector<int> &v : pairs){
            if(v[0] > end)
                end = v[1], ans++;
            else if(v[1] < end)
                end = v[1];
        }

        return ans;
    }
};