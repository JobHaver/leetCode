class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = 0;

        for(int i : nums)
            m[i]++;

        for(pair<const int, int> &p : m){
            if(p.second == 1)
                return -1;

            ans += p.second / 3;
            if(p.second % 3 != 0)
                ans++;
        }

        return ans;
    }
};