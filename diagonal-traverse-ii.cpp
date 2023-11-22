class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int, int>> q;
        int size = 0, i = 0;
        for(vector<int> &v : nums)
            size += v.size();

        vector<int> ans(size);
        for(q.push({0, 0}); !q.empty(); q.pop()){ //bfs
            auto [x, y] = q.front();
            ans[i++] = nums[x][y];

            if(!y && x + 1 < nums.size())
                q.push({x + 1, y});
            if(y + 1 < nums[x].size())
                q.push({x, y + 1});
        }
            
        return ans;
    }
};