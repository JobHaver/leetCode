class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int l, int r){
            int lc = __builtin_popcount(l), rc = __builtin_popcount(r);
            return lc == rc ? l < r : lc < rc;
        });

        return arr;
    }
};