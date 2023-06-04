class Solution {
private:
    vector<int> groups;

    void dfs(int group, int i, vector<vector<int>>& isConnected){
        groups[i] = group;
        for(int j = 0; j < isConnected.size(); j++){
            if(isConnected[i][j] && !groups[j])
                dfs(group, j, isConnected);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        groups.resize(size);
        int group = 1;

        for(int i = 0; i < size; i++){
            if(!groups[i])
                dfs(group++, i, isConnected);
        }

        return group - 1;
    }
};