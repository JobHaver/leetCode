class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](const int& a, const int& b) {
            int bitcountA = __builtin_popcount(a);
            int bitcountB = __builtin_popcount(b);

            if(bitcountA == bitcountB)
                return a < b;

            return bitcountA < bitcountB;
        });

        return arr;
    }
};