class Solution {
private:
    vector<bool> visited;
    vector<bool> safe;
    vector<vector<int>> *g;

    bool helper(int i){
        if(visited[i])
            return safe[i];
        
        visited[i] = true;

        bool s = true;
        for(int n : (*g)[i])
            s = s && helper(n);

        return safe[i] = s;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int size = graph.size();
        visited.resize(size);
        safe.resize(size);
        g = &graph;

        for(int i = 0; i < size; i++)
            helper(i);

        vector<int> ans;
        for(int i = 0; i < size; i++)
            if(safe[i]) ans.push_back(i);

        return ans;
    }
};