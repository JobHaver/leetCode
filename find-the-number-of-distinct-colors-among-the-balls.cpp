class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        unordered_map<int, int> ballsMP;
        unordered_map<int, int> numCountMP;
        int diffBalls = 0, i = 0;

        for(vector<int> &v : queries){
            int & ball = ballsMP[v[0]];

            if(ball != 0 && --numCountMP[ball] == 0)
                diffBalls--;

            ball = v[1];
            if(++numCountMP[v[1]] == 1)
                diffBalls++;

            ans[i++] = diffBalls;
        }

        return ans;
    }
};