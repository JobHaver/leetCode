class Solution {
private:
    vector<bool> visited;
    vector<bool> safe;
    vector<vector<int>> g;

    bool helper(int i){
        if(visited[i])
            return safe[i];
        
        bool s = visited[i] = true;
        for(int n : g[i])
            if(!(s = helper(n))) break;

        return safe[i] = s;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses);
        safe.resize(numCourses);
        g.resize(numCourses);

        for(vector<int> &v : prerequisites)
            g[v[0]].push_back(v[1]);
        
        for(int i = 0; i < numCourses; i++)
            if(!helper(i)) return false;

        return true;
    }
};