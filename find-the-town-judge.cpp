class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCount(n + 1);
        for(int i = 0; i < trust.size(); i++)
            trustCount[trust[i][0]] = INT_MIN, trustCount[trust[i][1]]++;

        for(int i = 1, k = n - 1; i < trustCount.size(); i++)
            if(k == trustCount[i])
                return i;

        return -1;
    }
};