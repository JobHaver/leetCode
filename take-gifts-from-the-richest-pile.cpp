class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> g;
        long long ans = 0;

        for(int i : gifts)
            g.push(i);

        for(int i = 0; i++ < k; g.pop())
           g.push(sqrt(g.top()));

        for(; !g.empty(); g.pop())
            ans += g.top();

        return ans;
    }
};