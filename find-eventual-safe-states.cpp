class Solution {
private:
    vector<bool> visited;
    vector<bool> safe;
    vector<vector<int>> *g;

    bool helper(int i){
        if(visited[i])
            return safe[i];
        
        bool s = visited[i] = true;
        for(int j = 0; s && j < (*g)[i].size(); j++)
            s = helper((*g)[i][j]) && s;

        return safe[i] = s;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int size = graph.size();
        visited.resize(size);
        safe.resize(size);
        g = &graph;

        vector<int> ans;
        for(int i = 0; i < size; i++)
            if(helper(i)) ans.push_back(i);

        return ans;
    }
};