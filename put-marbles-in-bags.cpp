class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        int size = w.size() - 1;
        vector<int> pairs(size);
        long long ans = 0; //max - min cancles out and covers 0 and size

        for(int i = 0; i < size; i++)
            pairs[i] = w[i] + w[i + 1];

        sort(pairs.begin(), pairs.end());

        k--; //bc one k is already coverd as ends cancle out to 0
        for(int i = 0, j = size-1; i < k; i++, j--)
            ans += pairs[j] - pairs[i];
        
        return ans;
    }
};